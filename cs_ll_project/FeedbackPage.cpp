#include "feedbackpage.h"
#include "ui_feedbackpage.h"
#include "history.h"

FeedbackPage::FeedbackPage(QWidget *parent, ServerLogic *l, int id)
    : QDialog(parent)
    , ui(new Ui::FeedbackPage),
    logic(l),
    myId(id)
{
    ui->setupUi(this);
}

FeedbackPage::~FeedbackPage()
{
    delete ui;
}

void FeedbackPage::on_Button_sharemyfeedback_clicked()
{
    hide();
    History* h = new History(this, this->logic, this->myId);

    h -> show();
}
