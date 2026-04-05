#ifndef ISSUETICKET_H
#define ISSUETICKET_H

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

private:
    Ui::IssueTicket *ui;
};

#endif // ISSUETICKET_H
