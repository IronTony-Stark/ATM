//
// Created by Iron Tony on 23/10/2020.
//

#ifndef ATM_BTNNAVIGATETRANSACTIONSCOMMAND_H
#define ATM_BTNNAVIGATETRANSACTIONSCOMMAND_H

#include <views/Command.h>
#include <views/Navigatable.h>

class BtnNavigateTransactionsCommand : public Command {
public:
    explicit BtnNavigateTransactionsCommand(Navigatable& navigatable);

    void execute() override;

private:
    Navigatable& _navigatable;
};

#endif //ATM_BTNNAVIGATETRANSACTIONSCOMMAND_H
