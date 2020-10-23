//
// Created by Iron Tony on 23/10/2020.
//

#ifndef ATM_COMMAND_H
#define ATM_COMMAND_H

class Command {
public:
    virtual void execute() = 0;

protected:
    ~Command() = default;
};

#endif //ATM_COMMAND_H
