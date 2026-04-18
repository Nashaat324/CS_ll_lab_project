#define BOOST_ASIO_HAS_CO_AWAIT
#define BOOST_JSON_STACK_BUFFER_SIZE 1024
#include <boost/json/src.hpp>

#include <iostream>
#include <string_view>
#include <boost/asio.hpp>
#include <boost/asio/this_coro.hpp>

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

awaitable<void> handle_client(tcp::socket socket)
{
    try
    {
        char data[1024];


        auto [ec, bytes_read] = co_await socket.async_read_some(
            boost::asio::buffer(data),
            as_tuple(use_awaitable)
            );


        if (!ec)

        {
            auto json_value = boost::json::parse(std::string_view(data, bytes_read));
            auto json_object = json_value.as_object();
            auto json_message = json_object.at("message");
            auto json_sender = json_object.at("from");
            std::string message = boost::json::value_to<std::string>(json_message);
            std::string sender = boost::json::value_to<std::string>(json_sender);


            std::cout << "Server received: "
                      << sender << ": " << message << "\n";
            std::cout << "Server received(raw message): "
                      << std::string_view(data, bytes_read) << "\n";
        }
        else
        {
            std::cout << "Read error: " << ec.message() << "\n";
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

