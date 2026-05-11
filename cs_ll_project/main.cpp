
#include "loginpage.h"
#include "FeedbackPage.h"
#include "TcpNetworkClient.h"
#include "client.h"
#include "ServerLogic/ServerLogic.h"

#include <QApplication>
#include "issueticket.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setQuitOnLastWindowClosed(false);

    // 1. Create the shared components ONCE
    TcpNetworkClient* net = new TcpNetworkClient();
    ServerLogic* log = new ServerLogic();

    // 2. Setup the Login Window with the required pointers
    LoginPage w(net, log);

    w.show();

    return a.exec();

}
