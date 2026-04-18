
#include "loginpage.h"
#include "FeedbackPage.h"


#include <QApplication>
#include "issueticket.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginPage w;
    IssueTicket w1;

   FeedbackPage w2;

    w.show();

    return a.exec();
}
