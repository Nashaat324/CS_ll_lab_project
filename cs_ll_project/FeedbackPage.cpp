#include "feedbackpage.h"
#include "ui_feedbackpage.h"
#include "history.h"

FeedbackPage::FeedbackPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FeedbackPage)
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
    History* h = new History(this);

    h -> show();
}
