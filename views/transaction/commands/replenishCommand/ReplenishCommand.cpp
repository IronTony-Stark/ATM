//
// Created by Iron Tony on 23/10/2020.
//

#include <QtCore/QString>
#include "ReplenishCommand.h"
#include "views/transaction/Windows.h"

ReplenishCommand::ReplenishCommand(
        Navigatable& navigatable,
        OperationManager& operationManager,
        QLineEdit& editHowMuch) :
        _navigatable(navigatable),
        _operationManager(operationManager),
        _editHowMuch(editHowMuch) {}

void ReplenishCommand::execute() {
    QString amountStr = _editHowMuch.text();
    uint amount = _editHowMuch.text().toUInt();
    _operationManager.replenish(amount);
    _navigatable.navigate(TRANSACTIONS);
}
