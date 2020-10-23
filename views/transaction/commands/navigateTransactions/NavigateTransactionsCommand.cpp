//
// Created by Iron Tony on 23/10/2020.
//

#include "NavigateTransactionsCommand.h"
#include "views/transaction/Windows.h"

NavigateTransactionsCommand::NavigateTransactionsCommand(Navigatable& navigatable) :
        _navigatable(navigatable) {}

void NavigateTransactionsCommand::execute() {
    _navigatable.navigate(TRANSACTIONS);
}
