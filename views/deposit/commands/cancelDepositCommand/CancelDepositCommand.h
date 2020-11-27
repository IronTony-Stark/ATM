//
// Created by Iron Tony on 23/10/2020.
//

#ifndef ATM_CANCELDEPOSITCOMMAND_H
#define ATM_CANCELDEPOSITCOMMAND_H

#include <views/Command.h>
#include <logics/managers/OperationManager.h>
#include <views/MessageDisplay.h>
#include <views/Navigatable.h>

class CancelDepositCommand : public Command {
public:
    CancelDepositCommand(Navigatable& navigatable,
                         Deposit*& selectedDeposit,
                         OperationManager& operationManager,
                         MessageDisplay& messageDisplay);

    void execute() override;

private:
    Navigatable& _navigatable;
    Deposit*& _selectedDeposit;
    OperationManager& _operationManager;
    MessageDisplay& _messageDisplay;
};

#endif //ATM_CANCELDEPOSITCOMMAND_H
