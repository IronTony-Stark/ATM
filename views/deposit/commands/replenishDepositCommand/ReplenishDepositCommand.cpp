//
// Created by Iron Tony on 23/10/2020.
//

#include "ReplenishDepositCommand.h"

ReplenishDepositCommand::ReplenishDepositCommand(
        Deposit*& selectedDeposit,
        OperationManager& operationManager,
        QLineEdit& replenishAmount,
        MessageDisplay& messageDisplay) :
        _selectedDeposit(selectedDeposit),
        _operationManager(operationManager),
        _replenishAmount(replenishAmount),
        _messageDisplay(messageDisplay) {}

void ReplenishDepositCommand::execute() {
    if (_selectedDeposit == nullptr) {
        _messageDisplay.show("Select deposit you want to replenish");
        return;
    }

    if (!_replenishAmount.hasAcceptableInput()) {
        _messageDisplay.show("Replenish amount is invalid");
        return;
    }

    uint amount = _replenishAmount.text().toUInt();
    try {
        _operationManager.replenishDeposit(_selectedDeposit->id(), amount);
        // TODO update ui on deposit replenishment
        _messageDisplay.show("Deposit Replenished Successfully", false);
    } catch (const std::exception& e) {
        _messageDisplay.show(e.what());
    }
}
