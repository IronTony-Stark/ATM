//
// Created by Iron Tony on 23/10/2020.
//

#ifndef ATM_CANCELPAYMENTCOMMAND_H
#define ATM_CANCELPAYMENTCOMMAND_H

#include <views/Command.h>
#include <views/Navigatable.h>
#include <logics/managers/OperationManager.h>

class CancelPaymentCommand : public Command {
public:
    explicit CancelPaymentCommand(OperationManager& operationManager);

    void execute() override;

private:
    OperationManager& _operationManager;
};


#endif //ATM_CANCELPAYMENTCOMMAND_H
