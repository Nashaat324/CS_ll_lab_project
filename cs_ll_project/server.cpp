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


        std::string dest;
        while(true)
        {
        auto [ec, bytes_read] = co_await socket_ptr->async_read_some(
            boost::asio::buffer(data),
            as_tuple(use_awaitable)
            );

            if(ec)
            {
            std::cout <<"client disconnected";
                connected_clients.erase(my_username);
                break;
            }

            auto json_value = boost::json::parse(std::string_view(data, bytes_read));
            auto json_object = json_value.as_object();
            std::string type = json_object.at("type").as_string().c_str();

            if(type == "login")
            {
                std::string username = json_object.at("user").as_string().c_str();

                connected_clients[username] = socket_ptr;
                std::cout << username << " has logged in. \n";

            }
            else if (type == "message")
            {
                 dest = json_object.at("to").as_string().c_str();
                if(connected_clients.count(dest))
                 {
                auto target_socket = connected_clients[dest];
               co_await boost::asio::async_write(*target_socket,
                boost::asio::buffer(data, bytes_read), use_awaitable);

                std::cout << "Routed message from " << my_username << "to " << dest << "\n";
                }
                }
            }
    }

    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << "\n";
    }
}

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

