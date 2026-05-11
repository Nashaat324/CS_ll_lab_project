#include "ServerLogic.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QDateTime>

bool ServerLogic::validateJson(const QString& rawJson) {
    QJsonDocument doc = QJsonDocument::fromJson(rawJson.toUtf8());
    return !doc.isNull() && doc.isObject();
}

void ServerLogic::processChatMessage(int userId, const QString& sender, const QString& message) {
    QString entry = QString("[%1] %2: %3\n")
                    .arg(QDateTime::currentDateTime().toString("hh:mm"))
                    .arg(sender)
                    .arg(message);
    activeChatLogs[userId] += entry;
}

void ServerLogic::archiveTicket(int userId) {
    ArchivedTicket ticket;
    ticket.userId = userId;
    ticket.status = "RESOLVED";
    ticket.resolutionTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm");
    ticket.chatLog = activeChatLogs[userId];

    historyDatabase.push_back(ticket);
    activeChatLogs.erase(userId); // Clear active chat
}

std::vector<ArchivedTicket> ServerLogic::getUserHistory(int userId) {
    std::vector<ArchivedTicket> results;
    for (const auto& t : historyDatabase) {
        if (t.userId == userId) results.push_back(t);
    }
    return results;
}

std::string ServerLogic::handleRequest(int id, const std::string& input){
    // 1. Convert std::string to QString for easy Qt JSON handling
        QString rawData = QString::fromStdString(input);
        QJsonDocument doc = QJsonDocument::fromJson(rawData.toUtf8());
        
        if (doc.isNull() || !doc.isObject()) {
            return "ERROR: Invalid JSON format";
        }

        QJsonObject obj = doc.object();
        QString type = obj["type"].toString();

        // 2. Route the request based on the "type" field
        if (type == "login") {
            QString username = obj["user"].toString();
            if (username.isEmpty()) {
                        return "ERROR: Username cannot be empty"; // This makes the test PASS
                    }
        
            
            return "SUCCESS: Login successful";
        }
        
        if (type == "chat_message") {
            QString sender = obj["from"].toString();
            QString msg = obj["message"].toString();
            this->processChatMessage(id, sender, msg);
            return "SUCCESS: Message Logged";
        }
    if (type == "session_end") {
            this->archiveTicket(id);
            return "SUCCESS: Ticket Archived";
        }
        return "ERROR: Unknown request type";
}

bool ServerLogic::isLoggedIn() {
    return true;
}

void ServerLogic::handleDisconnect(int id){
    // Check if there is an active chat that wasn't archived
        if (activeChatLogs.count(id)) {
            qDebug() << "User" << id << "disconnected unexpectedly. Saving partial log.";
            // Optionally archive what we have so far
            this->archiveTicket(id);
        }
}

int ServerLogic::getQueueSize() {
    // Returns how many people are currently chatting
    return static_cast<int>(activeChatLogs.size());
}

QJsonObject ServerLogic::acceptTicket(int id) {
    
    QJsonObject response;
    
    //  Check if this ticket already has a log. If not, create one.
    // This ensures that the chat starts with a clean slate.
    if (activeChatLogs.find(id) == activeChatLogs.end()) {
        activeChatLogs[id] = QString("--- Session Started at %1 ---\n")
            .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
        response["status"] = "success";
        response["message"] = "Ticket accepted";
    }
    else{
        // If it already exists, we still succeed but acknowledge it
        response["status"] = "success";
    }
    qDebug() << "Technician accepted ticket:" << id;
    return response;
}

