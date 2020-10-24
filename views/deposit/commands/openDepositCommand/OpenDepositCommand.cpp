//
// Created by Iron Tony on 23/10/2020.
//

#include "OpenDepositCommand.h"
#include "views/deposit/Windows.h"

OpenDepositCommand::OpenDepositCommand(
        Navigatable& navigatable,
        OperationManager& operationManager,
        DepositWidget& depositWidget,
        MessageDisplay& messageDisplay) :
        _navigatable(navigatable),
        _operationManager(operationManager),
        _depositWidget(depositWidget),
        _messageDisplay(messageDisplay) {}

void OpenDepositCommand::execute() {
    QString name;
    uint amount;
    uint period;
    QDateTime start;
    QDateTime end;
    uint percentage;
    std::tie(name, amount, period, start, end, percentage) = _depositWidget.data();
    try {
        _operationManager.startDeposit(name, amount, period, start, end, percentage);
        _navigatable.navigate(DEPOSIT_MENU);
    } catch (const std::exception& e) {
        _messageDisplay.show(e.what());
    }
}
