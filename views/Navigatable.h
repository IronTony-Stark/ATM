//
// Created by Iron Tony on 22/10/2020.
//

#ifndef ATM_NAVIGATABLE_H
#define ATM_NAVIGATABLE_H

class Navigatable {
public:
    virtual void navigate(int) = 0;

protected:
    ~Navigatable() = default;
};

#endif //ATM_NAVIGATABLE_H
