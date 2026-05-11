#include "ServerLogic.h"
#include <iostream>
#include <algorithm>


/*
  This receives every single message from the network and routes it
  to the correct helper function based on the "type" field.
 */
std::string ServerLogic::handleRequest(int clientID, const std::string& rawMessage){
    try{
        json data = json::parse(rawMessage);
        json response;
        
        std::string type = data.value("type", "unknown");
        
        if(type == "login"){
            response = doLogin(clientId, data);
        }
        else if (type == "submit_ticket") {
            response = doSubmitTicket(clientId, data);
        }
        else if (type == "accept_ticket") {
            response = acceptTicket(clientId);
        }
        else if(type == "chat"){
            response = doChat(clientId, data);
        }
        else if (type == "end_chat") {
            response = endChat(clientId);
        }
        else{
            response = {{"status", "error"}, {"message", "Uknown request type"}};
        }
        return response.dump(); //Convert the JSON response back to a string to send over the network
    }
    catch(const std::exception& e){
        // Fallback if the client sends corrupted or non-JSON data
        return "{\"status\":\"error\",\"message\":\"Invalid JSON format\"}";
    }
}


/*
  Handles user identification.
  We store the user's name and their role (Employee vs Technician)
  in a map so we can control what they are allowed to do later.
 */
json ServerLogic::doLogin(int clientId, const json&data){
    std::string username = data.value("user", "");
    std::string role = data.value("role", "employee"); // Defaults to employee
    
    if(username.empty()){
        return {{"status", "error"}, {"message", "Username cannot be empty"}};
    }
    
    // Store in the 'clients' map using the unique socket ID (clientId)
    clients[clientId] = {username, role};
    
    std::cout << "Login: " << username << " as " << role << " (ID: " << clientId << ")" << std::endl;
    
    return {{"status", "ok"}, {"role", role}, {"message", "Welcome " + name}};
}

    json ServerLogic::doChat(int clientId, const json& data){
        if(clients.find(clientId) == clients.end()){
            
        }
    }

/*
  Employee Logic: Creates a support request.
  Takes the dropdown data (category/issue) and saves it in the 'pendingTickets' vector.
 */
    json ServerLogic::doSubmitTicket(int clientId, const json& data) {
        // Security check: must be logged in
        if (clients.find(clientId) == clients.end()) {
            return {{"status", "error"}, {"message", "Must login first"}};
        }

        Ticket newTicket;
        newTicket.clientId = clientId;
        newTicket.category = data.value("category", "General");       // Hardware/Software
        newTicket.specificIssue = data.value("issue", "Not specified"); // Specific problem
        newTicket.description = data.value("description", "");        // Text box
        newTicket.preferredTech = data.value("tech", "Any");

        // Push to the back of the queue (First-In, First-Out)
        pendingTickets.push_back(newTicket);
        Queue.push_back(clientId);

        return {
            {"status", "ok"},
            {"position", (int)Queue.size()}, // Tells the user how many people are ahead of them
            {"message", "Ticket submitted successfully"}
        };
    }

/*
  Technician Logic: Connects a Tech to the next waiting Employee.
  This is the "Bridge" that links two different socket IDs together.
 */
json ServerLogic::acceptTicket(int adminId) {
    // Role check: Only techs can pull from the queue
    if (clients[adminId].role != "technician") {
        return {{"status", "error"}, {"message", "Only technicians can accept tickets"}};
    }
    if (pendingTickets.empty()) {
        return {{"status", "error"}, {"message", "No tickets waiting"}};
    }

    // Get the ticket at the front of the vector (index 0)
    Ticket t = pendingTickets.front();
    int empId = t.clientId;

    // ACTIVE CHATS MAP: This links the Technician ID to the Employee ID
    activeChats[adminId] = empId;
    activeChats[empId] = adminId;

    // Remove the ticket from the list since it is now being handled
    pendingTickets.erase(pendingTickets.begin());
    Queue.erase(std::remove(Queue.begin(), Queue.end(), empId), Queue.size() > 0 ? Queue.end() : Queue.begin());

    return {
        {"status", "ok"},
        {"chat_with", clients[empId].username},
        {"issue", t.specificIssue},
        {"details", t.description}
    };
}

/*
  Live Chat Routing Logic.
  This looks at who sent the message, finds their partner in 'activeChats',
  and returns a target ID so the network layer knows where to deliver the text.
 */
    json ServerLogic::doChat(int clientId, const json& data) {
        if (activeChats.find(clientId) == activeChats.end()) {
                return {{"status", "error"}, {"message", "No active chat partner"}};
            }

        int receiverId = activeChats[clientId];  // Find the partner's ID

        return {
            {"status", "ok"},
            {"type", "broadcast"},
            {"to_id", receiverId},  // The "Destination" for the network layer
            {"from", senderName},
            {"content", data.value("content", "")}
        };
    }

    void ServerLogic::handleDisconnect(int clientId) {
        endChat(clientId); // Clean up chats
        clients.erase(clientId);
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


/*
  Cleanup: Removes the link between users and cleans up the maps.
 */
json ServerLogic::endChat(int userId) {
    if (activeChats.count(userId)) {
        int partnerId = activeChats[userId];
        activeChats.erase(userId);
        activeChats.erase(partnerId);
        return {{"status", "ok"}, {"message", "Chat ended"}};
    }
    return {{"status", "error"}, {"message", "No active chat"}};
}
