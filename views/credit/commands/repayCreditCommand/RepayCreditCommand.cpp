//
// Created by Iron Tony on 23/10/2020.
//

#include <QtWidgets/QMessageBox>
#include "RepayCreditCommand.h"

RepayCreditCommand::RepayCreditCommand(
        OperationManager& operationManager,
        MessageDisplay& messageDisplay) :
        _operationManager(operationManager),
        _messageDisplay(messageDisplay) {}

void RepayCreditCommand::execute() {
    try {
        _operationManager.repayCredit(-1);
    } catch (const std::exception& e) {
        _messageDisplay.show(e.what());
    }
}
