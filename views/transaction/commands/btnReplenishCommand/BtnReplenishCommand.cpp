//
// Created by Iron Tony on 23/10/2020.
//

#include <QtCore/QString>
#include "BtnReplenishCommand.h"
#include "views/transaction/Windows.h"

BtnReplenishCommand::BtnReplenishCommand(
        Navigatable& navigatable,
        OperationManager& operationManager,
        QLineEdit& editHowMuch) :
        _navigatable(navigatable),
        _operationManager(operationManager),
        _editHowMuch(editHowMuch) {}

void BtnReplenishCommand::execute() {
    QString amountStr = _editHowMuch.text();
    uint amount = _editHowMuch.text().toUInt();
    _operationManager.replenish(amount);
    _navigatable.navigate(TRANSACTIONS);
}
