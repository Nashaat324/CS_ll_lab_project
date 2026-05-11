#ifndef SERVERLOGIC_H
#define SERVERLOGIC_H

#include <QString>
#include <vector>
#include <map>
#include <string>
#include <QJsonObject>
#include "SharedStructures.h"

class ServerLogic {
public:
    ServerLogic() = default;

    bool validateJson(const QString& rawJson);
    void processChatMessage(int userId, const QString& sender, const QString& message);
    void archiveTicket(int userId);
    
    std::string handleRequest(int id,const std::string& input);
    bool isLoggedIn();
    void handleDisconnect(int id);
    int getQueueSize();
    QJsonObject acceptTicket(int id);
    QString getChatLog(int userId);
    

    // For the History Window
    std::vector<ArchivedTicket> getUserHistory(int userId);

private:
    std::map<int, QString> activeChatLogs; // userId -> combined strings
    std::vector<ArchivedTicket> historyDatabase;
    std::map<int, QString> ticketOwners;
};

#endif
