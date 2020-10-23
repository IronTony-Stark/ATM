//
// Created by Vladyslav Synytsyn on 23/10/2020.
//

#ifndef ATM_CUSTOMERREGISTRATIONEXCEPTION_H
#define ATM_CUSTOMERREGISTRATIONEXCEPTION_H


#include <stdexcept>
#include <QtCore/QString>

class CustomerRegistrationException final: public std::exception {
private:
    const std::string _message;

public:

    explicit CustomerRegistrationException(std::string message): _message(std::move(message)){}

    const char* what() {
        return _message.c_str();
    }
};

std::ostream& operator<< (std::ostream& os, CustomerRegistrationException& ex);


#endif //ATM_CUSTOMERREGISTRATIONEXCEPTION_H
