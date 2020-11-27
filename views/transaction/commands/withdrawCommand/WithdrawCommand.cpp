//
// Created by Iron Tony on 23/10/2020.
//

#include <QtCore/QString>
#include "WithdrawCommand.h"
#include "views/transaction/Windows.h"

WithdrawCommand::WithdrawCommand(
        Navigatable& navigatable,
        OperationManager& operationManager,
        QLineEdit& editHowMuch,
        MessageDisplay& messageDisplay) :
        _navigatable(navigatable),
        _operationManager(operationManager),
        _editHowMuch(editHowMuch),
        _messageDisplay(messageDisplay) {}

void WithdrawCommand::execute() {
    if (!_editHowMuch.hasAcceptableInput()) {
        _messageDisplay.show("Amount is invalid");
        return;
    }

    uint amount = _editHowMuch.text().toUInt();
    try {
        _operationManager.withdraw(amount);
        _navigatable.navigate(TRANSACTIONS);
    } catch (const std::exception& e) {
        _messageDisplay.show(e.what());
    }
}
