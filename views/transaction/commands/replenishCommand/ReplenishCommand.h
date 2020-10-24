//
// Created by Iron Tony on 23/10/2020.
//

#ifndef ATM_REPLENISHCOMMAND_H
#define ATM_REPLENISHCOMMAND_H

#include <views/Command.h>
#include <views/Navigatable.h>
#include <logics/managers/OperationManager.h>
#include <QtWidgets/QLineEdit>

class ReplenishCommand : public Command {
public:
    explicit ReplenishCommand(Navigatable& navigatable,
                              OperationManager& operationManager,
                              QLineEdit& editHowMuch);

    void execute() override;

private:
    Navigatable& _navigatable;
    OperationManager& _operationManager;
    QLineEdit& _editHowMuch;
};


#endif //ATM_REPLENISHCOMMAND_H
