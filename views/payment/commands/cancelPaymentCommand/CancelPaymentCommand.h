//
// Created by Iron Tony on 23/10/2020.
//

#ifndef ATM_CANCELPAYMENTCOMMAND_H
#define ATM_CANCELPAYMENTCOMMAND_H

#include <views/Command.h>
#include <views/Navigatable.h>
#include <logics/managers/OperationManager.h>
#include <views/MessageDisplay.h>

class CancelPaymentCommand : public Command {
public:
    CancelPaymentCommand(Navigatable& navigatable,
                         RegularPayment*& selectedPayment,
                         OperationManager& operationManager,
                         MessageDisplay& messageDisplay);

    void execute() override;

private:
    Navigatable& _navigatable;
    RegularPayment*& _selectedPayment;
    OperationManager& _operationManager;
    MessageDisplay& _messageDisplay;
};


#endif //ATM_CANCELPAYMENTCOMMAND_H
