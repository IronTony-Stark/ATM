//
// Created by Iron Tony on 23/10/2020.
//

#include <QtCore/QString>
#include "ReplenishCommand.h"
#include "views/transaction/Windows.h"

ReplenishCommand::ReplenishCommand(
        Navigatable& navigatable,
        OperationManager& operationManager,
        QLineEdit& editHowMuch,
        MessageDisplay& messageDisplay) :
        _navigatable(navigatable),
        _operationManager(operationManager),
        _editHowMuch(editHowMuch),
        _messageDisplay(messageDisplay) {}

void ReplenishCommand::execute() {
    if (!_editHowMuch.hasAcceptableInput()) {
        _messageDisplay.show("Amount is invalid");
        return;
    }

    QString amountStr = _editHowMuch.text();
    uint amount = _editHowMuch.text().toUInt();
    _operationManager.replenish(amount);
    _navigatable.navigate(TRANSACTIONS);
}
