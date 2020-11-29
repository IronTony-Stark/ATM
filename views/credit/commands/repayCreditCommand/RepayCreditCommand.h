//
// Created by Iron Tony on 23/10/2020.
//

#ifndef ATM_REPAYCREDITCOMMAND_H
#define ATM_REPAYCREDITCOMMAND_H

#include <views/Command.h>
#include <logics/managers/OperationManager.h>
#include <views/MessageDisplay.h>
#include <views/Navigatable.h>

class RepayCreditCommand : public Command {
public:
    RepayCreditCommand(Credit*& selectedCredit,
                       Navigatable& navigatable,
                       OperationManager& operationManager,
                       MessageDisplay& messageDisplay);

    void execute() override;

private:
    Credit*& _selectedCredit;
    Navigatable& _navigatable;
    OperationManager& _operationManager;
    MessageDisplay& _messageDisplay;
};


#endif //ATM_REPAYCREDITCOMMAND_H
