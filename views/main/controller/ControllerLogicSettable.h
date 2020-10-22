//
// Created by Iron Tony on 22/10/2020.
//

#ifndef ATM_CONTROLLERLOGICSETTABLE_H
#define ATM_CONTROLLERLOGICSETTABLE_H

#include "ControllerLogic.h"

class ControllerLogicSettable {
public:
    virtual void setLogic(ControllerLogic*) = 0;

protected:
    ~ControllerLogicSettable() = default;
};

#endif //ATM_CONTROLLERLOGICSETTABLE_H
