//
// Created by Iron Tony on 23/10/2020.
//

#include <QtWidgets/QMessageBox>
#include "TakeCreditCommand.h"
#include "views/credit/Windows.h"

TakeCreditCommand::TakeCreditCommand(
        Navigatable& navigatable,
        CreditWidget& widgetTakeCredit,
        OperationManager& operationManager,
        MessageDisplay& messageDisplay) :
        _navigatable(navigatable),
        _widgetTakeCredit(widgetTakeCredit),
        _operationManager(operationManager),
        _messageDisplay(messageDisplay) {}

void TakeCreditCommand::execute() {
    if (!_widgetTakeCredit.validateInput())
        return;

    QString name;
    uint sum;
    uint period;
    uint payment;
    QDateTime start;
    QDateTime end;
    std::tie(name, sum, period, payment, start, end) = _widgetTakeCredit.data();
    try {
        _operationManager.takeCredit(name, sum, period, start, end);
        _messageDisplay.show(QString::number(sum) + " added to card balance", false);
        _navigatable.navigate(CREDITS_MENU);
    } catch (const std::exception& e) {
        _messageDisplay.show(e.what());
    }
}
