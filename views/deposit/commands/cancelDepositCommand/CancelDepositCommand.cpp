//
// Created by Iron Tony on 23/10/2020.
//

#include "CancelDepositCommand.h"

CancelDepositCommand::CancelDepositCommand(OperationManager& operationManager) :
        _operationManager(operationManager) {}

void CancelDepositCommand::execute() {
    _operationManager.cancelDeposit(-1);
}
