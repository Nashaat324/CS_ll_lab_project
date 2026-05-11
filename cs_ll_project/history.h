#ifndef HISTORY_H
#define HISTORY_H

#include <QDialog>
#include "ServerLogic/ServerLogic.h"

namespace Ui {
class History;
}

class History : public QDialog
{
    Q_OBJECT

public:
    explicit History(QWidget *parent = nullptr, ServerLogic *l = nullptr, int id = -1);
    ~History();

private slots:
    void on_pushButton_history_clicked();

private:
    Ui::History *ui;
    ServerLogic *logic;
    int myId;
};

#endif // HISTORY_H
