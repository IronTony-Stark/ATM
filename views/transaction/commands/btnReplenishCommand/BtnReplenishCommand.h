//
// Created by Iron Tony on 23/10/2020.
//

#ifndef ATM_BTNREPLENISHCOMMAND_H
#define ATM_BTNREPLENISHCOMMAND_H

#include <views/Command.h>
#include <views/Navigatable.h>
#include <logics/managers/OperationManager.h>
#include <QtWidgets/QLineEdit>

class BtnReplenishCommand : public Command {
public:
    explicit BtnReplenishCommand(Navigatable& navigatable,
                                 OperationManager& operationManager,
                                 QLineEdit& editHowMuch);

    void execute() override;

private:
    Navigatable& _navigatable;
    OperationManager& _operationManager;
    QLineEdit& _editHowMuch;
};


#endif //ATM_BTNREPLENISHCOMMAND_H
