//
// Created by Iron Tony on 23/10/2020.
//

#ifndef ATM_OPENDEPOSITCOMMAND_H
#define ATM_OPENDEPOSITCOMMAND_H

#include <views/Command.h>
#include <views/Navigatable.h>
#include <logics/managers/OperationManager.h>
#include <views/MessageDisplay.h>
#include <views/deposit/depositWidget/DepositWidget.h>

class OpenDepositCommand : public Command {
public:
    OpenDepositCommand(Navigatable& navigatable,
                       OperationManager& operationManager,
                       DepositWidget& depositWidget,
                       MessageDisplay& messageDisplay);

    void execute() override;

private:
    Navigatable& _navigatable;
    OperationManager& _operationManager;
    DepositWidget& _depositWidget;
    MessageDisplay& _messageDisplay;
};

#endif //ATM_OPENDEPOSITCOMMAND_H
