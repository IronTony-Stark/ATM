//
// Created by Iron Tony on 23/10/2020.
//

#ifndef ATM_REPAYCREDITCOMMAND_H
#define ATM_REPAYCREDITCOMMAND_H

#include <views/Command.h>
#include <logics/managers/OperationManager.h>
#include <views/MessageDisplay.h>

class RepayCreditCommand : public Command {
public:
    RepayCreditCommand(Credit*& selectedCredit,
                       OperationManager& operationManager,
                       MessageDisplay& messageDisplay);

    void execute() override;

private:
    Credit*& _selectedCredit;
    OperationManager& _operationManager;
    MessageDisplay& _messageDisplay;
};


#endif //ATM_REPAYCREDITCOMMAND_H
