//
// Created by Vlad on 22-Oct-20.
//

#ifndef ATM_OPERATIONMANAGER_H
#define ATM_OPERATIONMANAGER_H

#include <logics/Customer.h>

class OperationManager {
public:
    bool authorizeCustomer(const QString& cardNumber, unsigned short pinCode);
    bool registerCustomer(const Customer& customer);
    bool transfer(const QString& cartNumberFrom, const QString& cartNumberFromTo);
    bool withdraw(unsigned int amount);
    void startDeposit(unsigned int startAmount);
    int endDeposit();
    void cancelDeposit();
    void setPayment(unsigned long amount, const QDate& date);
    void takeCredit(unsigned int amount);
    void repayCredit(unsigned int amount);
};


#endif //ATM_OPERATIONMANAGER_H
