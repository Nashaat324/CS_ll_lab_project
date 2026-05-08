#include "ServerLogic.h"
#include<iostream>

std::string ServerLogic::handleRequest(int clientID, const std::string& rawMessage){
    try{
        json data = json::parse(rawMessage);
        json response;

        std::string type = data.value("type", "unknown");

        if(type == "login"){
            response = doLogin(clientID, data);
        }
        else if(type == "chat"){
            response = doChat(clientID, data);
        }else if(type == "ticket")
        {
            response = doSubmitTicket(clientID, data);
        }else{
            response = {{"status", "error"}, {"message", "Unknown request type"}};
        }
        return response.dump();
    }
    catch(const std::exception& e){
        return "{\"status\":\"error\",\"message\":\"Invalid JSON format\"}";
    }
}

json ServerLogic::doLogin(int clientId, const json&data){
    std::string username = data.value("user", "");

    if(username.empty()){
        return {{"status", "error"}, {"message", "Username cannot be empty"}};
    }

    clients[clientId] = username;

    std::cout << "User " << username << "logged in from ID: " << clientId << std::endl;

    return {{"status", "ok"}, {"message", "Login successful"}};
}

json ServerLogic::doSubmitTicket(int clientId, const json& data) {
    if (clients.find(clientId) == clients.end()) {
        return {{"status", "error"}, {"message", "Must login first"}};
    }

    Ticket newTicket;
    newTicket.clientId = clientId;
    newTicket.category = data.value("category", "General");       // Hardware/Software
    newTicket.specificIssue = data.value("issue", "Not specified"); // Specific problem
    newTicket.description = data.value("description", "");        // Text box
    newTicket.preferredTech = data.value("tech", "Any");

    pendingTickets.push_back(newTicket);
    Queue.push_back(clientId);

    return {
        {"status", "ok"},
        {"position", Queue.size()},
        {"message", "Ticket submitted successfully"}
    };
}

json ServerLogic::doChat(int clientId, const json& data) {
    if (clients.find(clientId) == clients.end()) {
        return {{"status", "error"}, {"message", "Please login first"}};
    }

    std::string messageContent = data.value("content", "");
    std::string senderName = clients[clientId];

    return {
        {"status", "ok"},
        {"type", "broadcast"},
        {"from", senderName},
        {"content", messageContent}
    };
}

void ServerLogic::handleDisconnect(int clientId) {
    if (clients.count(clientId)) {
        std::cout << "User " << clients[clientId] << " disconnected." << std::endl;
        clients.erase(clientId);
    }
}

json ServerLogic::getNextTicket(int adminId) {
    if (pendingTickets.empty()) {
        return {{"status", "empty"}, {"message", "No pending tickets."}};
    }

    Ticket t = pendingTickets.front();
    pendingTickets.erase(pendingTickets.begin());
    Queue.erase(Queue.begin());

    return {
        {"status", "ok"},
        {"client_id", t.clientId},
        {"category", t.category},
        {"issue", t.specificIssue},
        {"description", t.description}
    };
}
bool ServerLogic::isLoggedIn(int clientId) const
{
    return clients.find(clientId)
    != clients.end();
}

int ServerLogic::getQueueSize() const
{
    return Queue.size();
}

