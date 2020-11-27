//
// Created by Iron Tony on 23/10/2020.
//

#include <QtWidgets/QMessageBox>
#include "RepayCreditCommand.h"

RepayCreditCommand::RepayCreditCommand(
        Credit*& selectedCredit,
        OperationManager& operationManager,
        MessageDisplay& messageDisplay) :
        _selectedCredit(selectedCredit),
        _operationManager(operationManager),
        _messageDisplay(messageDisplay) {}

void RepayCreditCommand::execute() {
    if (_selectedCredit == nullptr) {
        _messageDisplay.show("Select credit you want to repay");
        return;
    }

    try {
        _operationManager.repayCredit(_selectedCredit->id());
        _messageDisplay.show("Credit Payed Successfully", false);
    } catch (const std::exception& e) {
        _messageDisplay.show(e.what());
    }
}
