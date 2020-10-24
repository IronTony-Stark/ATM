//
// Created by Iron Tony on 23/10/2020.
//

#ifndef ATM_CREATEPAYMENTCOMMAND_H
#define ATM_CREATEPAYMENTCOMMAND_H

#include <views/Command.h>
#include <views/Navigatable.h>
#include <logics/managers/OperationManager.h>
#include <views/MessageDisplay.h>
#include <views/payment/paymentWidget/PaymentWidget.h>

class CreatePaymentCommand : public Command {
public:
    explicit CreatePaymentCommand(Navigatable& navigatable,
                                  OperationManager& operationManager,
                                  PaymentWidget& paymentWidget,
                                  MessageDisplay& messageDisplay);

    void execute() override;

private:
    Navigatable& _navigatable;
    OperationManager& _operationManager;
    PaymentWidget& _paymentWidget;
    MessageDisplay& _messageDisplay;
};


#endif //ATM_CREATEPAYMENTCOMMAND_H
