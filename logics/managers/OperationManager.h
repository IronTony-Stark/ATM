//
// Created by Vlad on 22-Oct-20.
//

#ifndef ATM_OPERATIONMANAGER_H
#define ATM_OPERATIONMANAGER_H

#include <logics/Customer.h>

class OperationManager {
public:
    bool authorizeCustomer(const QString& cardNumber, unsigned short pinCode);
    void blockCustomer(const QString& cardNumber);
    ushort registerCustomer(const QString& name, const QString& phone, uint taxNumber, QString cardType);
    void replenish(uint amount);
    void withdraw(unsigned int amount);
    void transfer(const QString& cartNumberFromTo, uint amount);
    void startDeposit(unsigned int startAmount);
    int endDeposit();
    void cancelDeposit();
    void setPayment(unsigned long amount, const QDate& date);
    void takeCredit(unsigned int amount);
    void repayCredit(unsigned int amount);
};


#endif //ATM_OPERATIONMANAGER_H
