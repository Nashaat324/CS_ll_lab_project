#define BOOST_ASIO_HAS_CO_AWAIT
#define BOOST_JSON_STACK_BUFFER_SIZE 1024
#include <boost/json/src.hpp>

#include <iostream>
#include <string_view>
#include <boost/asio.hpp>
#include <boost/asio/this_coro.hpp>
#include <map>
#include <memory>

#include <boost/asio/use_awaitable.hpp>
#include <boost/asio/detached.hpp>
#include <boost/asio/as_tuple.hpp>
#include <boost/json.hpp>

using boost::asio::ip::tcp;
using boost::asio::awaitable;
using boost::asio::co_spawn;
using boost::asio::detached;
using boost::asio::use_awaitable;
using boost::asio::as_tuple;

std::map<std::string, std::shared_ptr<tcp::socket>> connected_clients;

awaitable<void> handle_client(tcp::socket socket)
{
    try
    {
        auto socket_ptr = std::make_shared<tcp::socket>(std::move(socket));
        std::string my_username = "";
        char data[1024];

        while(true)
        {
            auto [ec, bytes_read] = co_await socket_ptr->async_read_some(
                boost::asio::buffer(data),
                as_tuple(use_awaitable)
                );

            if(ec)
            {
                std::cout << "client disconnected\n";
                if (!my_username.empty()) connected_clients.erase(my_username);
                break;
            }

            auto json_value = boost::json::parse(std::string_view(data, bytes_read));
            auto& json_object = json_value.as_object();

            if (!json_object.contains("type")) {
                std::cout << "Received non-protocol data, skipping...\n";
                continue;
            }

            std::string type = json_object.at("type").as_string().c_str();

            if(type == "login") {
                if (json_object.contains("user")) {
                    std::string username = json_object.at("user").as_string().c_str();
                    my_username = username;
                    connected_clients[username] = socket_ptr;
                    std::cout << username << " has logged in.\n";
                }
            }
            else if (type == "chat_message") {
                if (json_object.contains("message") && json_object.contains("from") && json_object.contains("to")) {
                    std::string message = boost::json::value_to<std::string>(json_object.at("message"));
                    std::string sender = boost::json::value_to<std::string>(json_object.at("from"));
                    std::string dest = json_object.at("to").as_string().c_str();

                    std::cout << "Server received: " << sender << ": " << message << "\n";

                    if(connected_clients.count(dest))
                    {
                        auto target_socket = connected_clients[dest];
                        co_await boost::asio::async_write(*target_socket,
                                                          boost::asio::buffer(data, bytes_read), use_awaitable);

                        std::cout << "Routed message from " << sender << " to " << dest << "\n";
                    }

                    boost::json::object response;
                    response["type"] = "server_confirmation";
                    response["status"] = "delivered";
                    response["original_msg"] = message;

                    std::string response_str = boost::json::serialize(response) + "\n";
                    co_await boost::asio::async_write(*socket_ptr,
                                                      boost::asio::buffer(response_str), use_awaitable);
                }
            }
        } // End of while loop
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << "\n";
    }
} // End of handle_client

awaitable<void> listener()
{
    auto ex = co_await boost::asio::this_coro::executor;

    tcp::acceptor acceptor(ex, tcp::endpoint(tcp::v4(), 54321));

    std::cout << "Server is listening on 127.0.0.1:54321...\n";

    while (true)
    {
        auto [ec, socket] =
            co_await acceptor.async_accept(as_tuple(use_awaitable));

        if (!ec)
        {
            co_spawn(ex, handle_client(std::move(socket)), detached);
        }
        else
        {
            std::cout << "Accept error: " << ec.message() << "\n";
        }
    }
}

int main()
{
    boost::asio::io_context io_context;

    co_spawn(io_context, listener(), detached);

    io_context.run();

    return 0;
}
