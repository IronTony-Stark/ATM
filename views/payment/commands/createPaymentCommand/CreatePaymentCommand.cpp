//
// Created by Iron Tony on 23/10/2020.
//

#include "CreatePaymentCommand.h"
#include "views/payment/Windows.h"

CreatePaymentCommand::CreatePaymentCommand(
        Navigatable& navigatable,
        OperationManager& operationManager,
        PaymentWidget& paymentWidget,
        MessageDisplay& messageDisplay) :
        _navigatable(navigatable),
        _operationManager(operationManager),
        _paymentWidget(paymentWidget),
        _messageDisplay(messageDisplay) {}

void CreatePaymentCommand::execute() {
    if (!_paymentWidget.validateInput())
        return;

    QString name;
    uint amount;
    QString receiver;
    uint when;
    std::tie(name, amount, receiver, when) = _paymentWidget.data();
    try {
        _operationManager.setPayment(name, amount, receiver, when);
        _navigatable.navigate(PAYMENT_MENU);
    } catch (const std::exception& e) {
        _messageDisplay.show(e.what());
    }
}
