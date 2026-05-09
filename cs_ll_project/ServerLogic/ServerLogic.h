#ifndef SERVERLOGIC_H
#define SERVERLOGIC_H

#include <vector>
#include <string>
#include <map>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class ServerLogic {
public:
public:
    ServerLogic() = default;

    std::string handleRequest(
        int clientId,
        const std::string& rawMessage
        );

    void handleDisconnect(int clientId);

    bool isLoggedIn(int clientId) const;

    int getQueueSize() const;

private:

    struct Ticket {
        int clientId;
        std::string category;
        std::string specificIssue;
        std::string description;
        std::string preferredTech;
    };

    std::map<int, std::string> clients;
    std::vector<int> Queue;
    std::map<int, int> activeChats;

    std::vector<Ticket> pendingTickets;

    json doLogin(int clientId, const json& data);
    json doChat(int clientId, const json& data);
    json doSubmitTicket(int clientId, const json& data);
    json getNextTicket(int adminId);

};

#endif
