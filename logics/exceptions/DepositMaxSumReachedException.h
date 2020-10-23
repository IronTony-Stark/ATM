//
// Created by Vladyslav Synytsyn on 23/10/2020.
//

#ifndef ATM_DEPOSITMAXSUMREACHEDEXCEPTION_H
#define ATM_DEPOSITMAXSUMREACHEDEXCEPTION_H

#include <exception>
#include <string>

class DepositMaxSumReachedException final : std::exception {
public:
    explicit DepositMaxSumReachedException(std::string message): _message(std::move(message)){}

    const char* what()
    {
        return _message.c_str();
    }

private:
    std::string _message;
};


#endif //ATM_DEPOSITMAXSUMREACHEDEXCEPTION_H
