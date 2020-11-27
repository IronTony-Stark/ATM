//
// Created by Iron Tony on 23/10/2020.
//

#include <views/deposit/Windows.h>
#include "CancelDepositCommand.h"

CancelDepositCommand::CancelDepositCommand(
        Navigatable& navigatable,
        Deposit*& selectedDeposit,
        OperationManager& operationManager,
        MessageDisplay& messageDisplay) :
        _navigatable(navigatable),
        _selectedDeposit(selectedDeposit),
        _operationManager(operationManager),
        _messageDisplay(messageDisplay) {}

void CancelDepositCommand::execute() {
    if (_selectedDeposit == nullptr) {
        _messageDisplay.show("Select deposit you want to cancel");
        return;
    }

    _operationManager.cancelDeposit(_selectedDeposit->id());
    // TODO update ui on deposit cancelling
    _navigatable.navigate(DEPOSIT_MENU);
}
