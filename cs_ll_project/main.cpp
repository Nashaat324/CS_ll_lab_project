#include "issueticket.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IssueTicket w;
    w.show();
    return a.exec();
}
