#ifndef SHAREDSTRUCTURES_H
#define SHAREDSTRUCTURES_H

#include <QString>

struct ArchivedTicket {
    int userId;
    QString resolutionTime;
    QString status;
    QString chatLog; // To save the actual conversation
};

#endif // SHAREDSTRUCTURES_H
