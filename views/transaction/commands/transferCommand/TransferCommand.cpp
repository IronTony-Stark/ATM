//
// Created by Iron Tony on 23/10/2020.
//

#include <QtCore/QString>
#include "TransferCommand.h"
#include "views/transaction/Windows.h"

TransferCommand::TransferCommand(
        Navigatable& navigatable,
        OperationManager& operationManager,
        QLineEdit& editHowMuch,
        QLineEdit& editToWhom,
        MessageDisplay messageDisplay) :
        _navigatable(navigatable),
        _operationManager(operationManager),
        _editHowMuch(editHowMuch),
        _editToWhom(editToWhom),
        _messageDisplay(messageDisplay) {}

void TransferCommand::execute() {
    QString to = _editToWhom.text();
    uint amount = _editHowMuch.text().toUInt();
    try {
        _operationManager.transfer(to, amount);
        _navigatable.navigate(TRANSACTIONS);
    } catch (const std::exception& e) {
        _messageDisplay.show(e.what());
    }
}
