//
// Created by Iron Tony on 23/10/2020.
//

#ifndef ATM_NAVIGATETRANSACTIONSCOMMAND_H
#define ATM_NAVIGATETRANSACTIONSCOMMAND_H

#include <views/Command.h>
#include <views/Navigatable.h>

class NavigateTransactionsCommand : public Command {
public:
    explicit NavigateTransactionsCommand(Navigatable& navigatable);

    void execute() override;

private:
    Navigatable& _navigatable;
};

#endif //ATM_NAVIGATETRANSACTIONSCOMMAND_H
