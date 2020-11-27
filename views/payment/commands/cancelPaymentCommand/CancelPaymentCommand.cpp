//
// Created by Iron Tony on 23/10/2020.
//

#include <views/payment/Windows.h>
#include "CancelPaymentCommand.h"

CancelPaymentCommand::CancelPaymentCommand(
        Navigatable& navigatable,
        RegularPayment*& selectedPayment,
        OperationManager& operationManager,
        MessageDisplay& messageDisplay) :
        _navigatable(navigatable),
        _selectedPayment(selectedPayment),
        _operationManager(operationManager),
        _messageDisplay(messageDisplay) {}

void CancelPaymentCommand::execute() {
    if (_selectedPayment == nullptr) {
        _messageDisplay.show("Select payment you want to cancel");
        return;
    }

    _operationManager.cancelPayment(_selectedPayment->id());
    _navigatable.navigate(PAYMENT_MENU);
}
