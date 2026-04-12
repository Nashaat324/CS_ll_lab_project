#ifndef ISSUETICKET_H
#define ISSUETICKET_H
#include <QString>
#include <QWidget>

namespace Ui {
class IssueTicket;
}

class IssueTicket : public QWidget
{
    Q_OBJECT

public:
    explicit IssueTicket(QWidget *parent = nullptr);
    ~IssueTicket();


    void setUsername(QString username);

private slots:
    void on_pushButton_submit_clicked();
    void on_comboBox_category_currentTextChanged(const QString &arg1);
    void on_pushButton_reset_clicked();


     private:
    Ui::IssueTicket *ui;
    QString currentUsername;

    static int generalQueue;
    static int ahmedQueue;
    static int omarQueue;
    static int youssefQueue;
    static int mahmoudQueue;
    static int karimQueue;

};

#endif // ISSUETICKET_H
