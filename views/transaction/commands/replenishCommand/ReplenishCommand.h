//
// Created by Iron Tony on 23/10/2020.
//

#ifndef ATM_REPLENISHCOMMAND_H
#define ATM_REPLENISHCOMMAND_H

#include <views/Command.h>
#include <views/Navigatable.h>
#include <logics/managers/OperationManager.h>
#include <QtWidgets/QLineEdit>
#include <views/MessageDisplay.h>

class ReplenishCommand : public Command {
public:
    ReplenishCommand(Navigatable& navigatable,
                     OperationManager& operationManager,
                     QLineEdit& editHowMuch,
                     MessageDisplay& messageDisplay);

    void execute() override;

private:
    Navigatable& _navigatable;
    OperationManager& _operationManager;
    QLineEdit& _editHowMuch;
    MessageDisplay& _messageDisplay;
};


#endif //ATM_REPLENISHCOMMAND_H
