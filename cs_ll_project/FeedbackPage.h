#ifndef FEEDBACKPAGE_H
#define FEEDBACKPAGE_H

#include <QDialog>
#include "ServerLogic/ServerLogic.h"


namespace Ui {

class FeedbackPage;
}

class FeedbackPage : public QDialog
{
    Q_OBJECT

public:
    explicit FeedbackPage(QWidget *parent = nullptr, ServerLogic *l = nullptr, int id = -1);
    ~FeedbackPage();

private slots:
    void on_Button_sharemyfeedback_clicked();


private:
    Ui::FeedbackPage *ui;
    ServerLogic *logic;
    int myId;
};



#endif // FEEDBACKPAGE_H
