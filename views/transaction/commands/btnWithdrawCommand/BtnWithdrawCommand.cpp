//
// Created by Iron Tony on 23/10/2020.
//

#include <QtCore/QString>
#include "BtnWithdrawCommand.h"
#include "views/transaction/Windows.h"

BtnWithdrawCommand::BtnWithdrawCommand(
        Navigatable& navigatable,
        OperationManager& operationManager,
        QLineEdit& editHowMuch,
        MessageDisplay& messageDisplay) :
        _navigatable(navigatable),
        _operationManager(operationManager),
        _editHowMuch(editHowMuch),
        _messageDisplay(messageDisplay) {}

void BtnWithdrawCommand::execute() {
    uint amount = _editHowMuch.text().toUInt();
    try {
        _operationManager.withdraw(amount);
        _navigatable.navigate(TRANSACTIONS);
    } catch (const std::exception& e) {
        _messageDisplay.show(e.what());
    }
}
