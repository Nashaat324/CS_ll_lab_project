#include "feedbackpage.h"
#include "ui_feedbackpage.h"

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
