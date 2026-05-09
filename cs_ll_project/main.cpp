
#include "loginpage.h"
#include "FeedbackPage.h"
#include "TcpNetworkClient.h"
#include "client.h"


#include <QApplication>
#include "issueticket.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginPage w;
    IssueTicket w1;

   FeedbackPage w2;

 TcpNetworkClient* realNet = new TcpNetworkClient();

 Client* chatWindow = new Client(realNet);


    w.show();

    return a.exec();

}
