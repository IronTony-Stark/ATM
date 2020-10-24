//
// Created by Iron Tony on 23/10/2020.
//

#ifndef ATM_REPLENISHDEPOSITCOMMAND_H
#define ATM_REPLENISHDEPOSITCOMMAND_H

#include <views/Command.h>
#include <views/Navigatable.h>
#include <logics/managers/OperationManager.h>
#include <views/MessageDisplay.h>
#include <QtWidgets/QLineEdit>

class ReplenishDepositCommand : public Command {
public:
    ReplenishDepositCommand(OperationManager& operationManager,
                            QLineEdit& replenishAmount,
                            MessageDisplay& messageDisplay);

    void execute() override;

private:
    OperationManager& _operationManager;
    QLineEdit& _replenishAmount;
    MessageDisplay& _messageDisplay;
};

#endif //ATM_REPLENISHDEPOSITCOMMAND_H
