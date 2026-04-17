#include "FeedbackPage.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FeedbackPage w;
    w.show();
    return a.exec();
}
