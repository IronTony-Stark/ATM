//
// Created by Iron Tony on 23/10/2020.
//

#include "CancelPaymentCommand.h"

CancelPaymentCommand::CancelPaymentCommand(
        OperationManager& operationManager) :
        _operationManager(operationManager) {}

void CancelPaymentCommand::execute() {
    _operationManager.cancelPayment(0);
}
