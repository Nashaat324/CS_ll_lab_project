#ifndef FEEDBACKPAGE_H
#define FEEDBACKPAGE_H

#include <QDialog>

namespace Ui {
class FeedbackPage;
}

class FeedbackPage : public QDialog
{
    Q_OBJECT

public:
    explicit FeedbackPage(QWidget *parent = nullptr);
    ~FeedbackPage();

private slots:
    void on_Button_sharemyfeedback_clicked();


private:
    Ui::FeedbackPage *ui;
};



#endif // FEEDBACKPAGE_H
