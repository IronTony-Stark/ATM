//
// Created by Iron Tony on 23/10/2020.
//

#ifndef ATM_CANCELDEPOSITCOMMAND_H
#define ATM_CANCELDEPOSITCOMMAND_H

#include <views/Command.h>
#include <logics/managers/OperationManager.h>

class CancelDepositCommand : public Command {
public:
    CancelDepositCommand(OperationManager& operationManager);

    void execute() override;

private:
    OperationManager& _operationManager;
};

#endif //ATM_CANCELDEPOSITCOMMAND_H
