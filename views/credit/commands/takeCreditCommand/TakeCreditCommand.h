//
// Created by Iron Tony on 23/10/2020.
//

#ifndef ATM_TAKECREDITCOMMAND_H
#define ATM_TAKECREDITCOMMAND_H

#include <views/Command.h>
#include <views/Navigatable.h>
#include <logics/managers/OperationManager.h>
#include <views/MessageDisplay.h>
#include <views/credit/creditWidget/CreditWidget.h>

class TakeCreditCommand : public Command {
public:
    TakeCreditCommand(Navigatable& navigatable,
                      CreditWidget& widgetTakeCredit,
                      OperationManager& operationManager,
                      MessageDisplay& messageDisplay);

    void execute() override;

private:
    Navigatable& _navigatable;
    CreditWidget& _widgetTakeCredit;
    OperationManager& _operationManager;
    MessageDisplay& _messageDisplay;
};


#endif //ATM_TAKECREDITCOMMAND_H
