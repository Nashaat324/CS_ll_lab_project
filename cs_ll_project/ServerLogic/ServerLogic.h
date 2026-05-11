#ifndef SERVERLOGIC_H
#define SERVERLOGIC_H

#include <vector>
#include <string>
#include <map>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

struct Ticket {
    int clientId;
    std::string category;      // Hardware/Software
    std::string specificIssue; // Selected from dropdown
    std::string description;   // Text box
    std::string preferredTech; // Optional tech choice
};

//Stores both name and role
struct UserInfo {
    std::string username;
    std::string role; // "employee" or "technician"
};

class ServerLogic {
public:
    ServerLogic() = default;

    
    std::string handleRequest(int clientId, const std::string& rawMessage);
    
    void handleDisconnect(int clientId);

private:
    
    std::map<int, UserInfo> clients;  // clientId -> (name,role)
    std::map<int, int> activeChats;       // Maps Employee to Technician (and vice versa)
    std::vector<int> Queue;    // For tracking position
    std::vector<Ticket> pendingTickets;   // The actual ticket data
   
    
    json doLogin(int clientId, const json& data);
        json doSubmitTicket(int clientId, const json& data);
        json acceptTicket(int adminId);       // For Technicians to take a ticket
        json doChat(int senderId, const json& data);
        json endChat(int userId);             // To close a session
};

#endif
