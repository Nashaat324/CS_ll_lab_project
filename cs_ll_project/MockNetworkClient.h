#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class Client;
}

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();

    void setTechnician(const QString& tech);
    void setUsername(const QString& name);

private slots:
    void on_send_clicked();
    void onReadyRead();

private:
    Ui::Client *ui;
    QTcpSocket* socket;

    QString username;
    QString technician;
};

#endif
