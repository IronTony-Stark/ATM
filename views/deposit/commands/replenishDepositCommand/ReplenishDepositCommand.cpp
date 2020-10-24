//
// Created by Iron Tony on 23/10/2020.
//

#include "ReplenishDepositCommand.h"

ReplenishDepositCommand::ReplenishDepositCommand(
        OperationManager& operationManager,
        QLineEdit& replenishAmount,
        MessageDisplay& messageDisplay) :
        _operationManager(operationManager),
        _replenishAmount(replenishAmount),
        _messageDisplay(messageDisplay) {}

void ReplenishDepositCommand::execute() {
    uint amount = _replenishAmount.text().toUInt();
    try {
        _operationManager.replenishDeposit(-1, amount);
    } catch (const std::exception& e) {
        _messageDisplay.show(e.what());
    }
}
