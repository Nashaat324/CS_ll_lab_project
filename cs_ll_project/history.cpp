#include "history.h"
#include "ui_history.h"

History::History(QWidget *parent, ServerLogic *l, int id)
    : QDialog(parent),
    ui(new Ui::History),
    logic(l),    // Save the server logic pointer to our private variable
    myId(id)    // Save the user's ID so we know whose history to show
{
    ui->setupUi(this);
}

History::~History()
{
    delete ui;
}

void History::on_pushButton_history_clicked()
{
// 1. Clear the List Widget so we don't duplicate items if they click twice
    ui->listWidget_history->clear();

// 2. Safety Check: Make sure our logic pointer isn't broken (null)
if (logic != nullptr) {
        // Get the history from ServerLogic
        std::vector<ArchivedTicket> myHistory = logic->getUserHistory(myId);

        ui->listWidget_history->addItem("--- Official History for ID: " + QString::number(myId) + " ---");

        if (myHistory.empty()) {
            ui->listWidget_history->addItem("No past tickets found.");
        } else {
            for (const auto& ticket : myHistory) {
                QString entry = QString("[%1] Status: %2")
                .arg(ticket.resolutionTime)
                    .arg(ticket.status);
                ui->listWidget_history->addItem(entry);
            }
        }
    }

}


