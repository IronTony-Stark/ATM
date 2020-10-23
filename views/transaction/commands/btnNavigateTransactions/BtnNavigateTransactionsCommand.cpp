//
// Created by Iron Tony on 23/10/2020.
//

#include "BtnNavigateTransactionsCommand.h"
#include "views/transaction/Windows.h"

BtnNavigateTransactionsCommand::BtnNavigateTransactionsCommand(Navigatable& navigatable) :
        _navigatable(navigatable) {}

void BtnNavigateTransactionsCommand::execute() {
    _navigatable.navigate(TRANSACTIONS);
}
