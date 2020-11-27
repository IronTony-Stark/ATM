//
// Created by Iron Tony on 23/10/2020.
//

#ifndef ATM_TRANSFERCOMMAND_H
#define ATM_TRANSFERCOMMAND_H

#include <views/Command.h>
#include <views/Navigatable.h>
#include <logics/managers/OperationManager.h>
#include <QtWidgets/QLineEdit>
#include <views/MessageDisplay.h>

class TransferCommand : public Command {
public:
    TransferCommand(Navigatable& navigatable,
                    OperationManager& operationManager,
                    QLineEdit& editHowMuch,
                    QLineEdit& editToWhom,
                    MessageDisplay& messageDisplay);

    void execute() override;

private:
    Navigatable& _navigatable;
    OperationManager& _operationManager;
    QLineEdit& _editHowMuch;
    QLineEdit& _editToWhom;
    MessageDisplay& _messageDisplay;
};


#endif //ATM_TRANSFERCOMMAND_H
