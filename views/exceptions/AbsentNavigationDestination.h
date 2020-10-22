//
// Created by Iron Tony on 22/10/2020.
//

#ifndef ATM_ABSENTNAVIGATIONDESTINATION_H
#define ATM_ABSENTNAVIGATIONDESTINATION_H

#include <exception>
#include <string>
#include <utility>

class AbsentNavigationDestination : public std::exception {
public:
    explicit AbsentNavigationDestination(std::string msg) :
            _msg(std::move(msg)) {}

    [[nodiscard]] const char* what() const noexcept override {
        return _msg.c_str();
    }

private:
    std::string _msg;
};

#endif //ATM_ABSENTNAVIGATIONDESTINATION_H
