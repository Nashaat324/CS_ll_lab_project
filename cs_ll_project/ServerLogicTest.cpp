#include <gtest/gtest.h>
#include "ServerLogic/ServerLogic.h"//

TEST(ServerLogicTest, ValidLogin)
{
    ServerLogic server;

    std::string request =
        R"({"type":"login","user":"Nour"})";

    std::string response =
        server.handleRequest(1, request);

    EXPECT_TRUE(server.isLoggedIn(1));

    EXPECT_TRUE(
        response.find("Login successful")
        != std::string::npos
        );
}

TEST(ServerLogicTest, EmptyUsernameRejected)
{
    ServerLogic server;

    std::string request =
        R"({"type":"login","user":""})";

    std::string response =
        server.handleRequest(1, request);

    EXPECT_TRUE(
        response.find("Username cannot be empty")
        != std::string::npos
        );
}

TEST(ServerLogicTest, InvalidJsonRejected)
{
    ServerLogic server;

    std::string request =
        "{invalid json}";

    std::string response =
        server.handleRequest(1, request);

    EXPECT_TRUE(
        response.find("Invalid JSON format")
        != std::string::npos
        );
}

TEST(ServerLogicTest, ChatWithoutLoginRejected)
{
    ServerLogic server;

    std::string request =
        R"({"type":"chat","content":"Hello"})";

    std::string response =
        server.handleRequest(1, request);

    EXPECT_TRUE(
        response.find("Please login first")
        != std::string::npos
        );
}

TEST(ServerLogicTest, DisconnectRemovesUser)
{
    ServerLogic server;

    std::string loginRequest =
        R"({"type":"login","user":"Nour"})";

    server.handleRequest(1, loginRequest);

    server.handleDisconnect(1);

    EXPECT_FALSE(server.isLoggedIn(1));
}

TEST(ServerLogicTest, TicketSubmissionWorks)
{
    ServerLogic server;

    std::string loginRequest =
        R"({"type":"login","user":"Nour"})";

    server.handleRequest(1, loginRequest);

    std::string ticketRequest =
        R"({
            "type":"ticket",
            "category":"Hardware",
            "issue":"Keyboard",
            "description":"Broken keyboard",
            "tech":"Ahmed"
        })";

    std::string response =
        server.handleRequest(1, ticketRequest);

    EXPECT_TRUE(
        response.find("Ticket submitted successfully")
        != std::string::npos
        );

    EXPECT_EQ(server.getQueueSize(), 1);
}

TEST(ServerLogicTest, UnknownRequestRejected)
{
    ServerLogic server;

    std::string request =
        R"({"type":"banana"})";

    std::string response =
        server.handleRequest(1, request);

    EXPECT_TRUE(
        response.find("Unknown request type")
        != std::string::npos
        );
}
