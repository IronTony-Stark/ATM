//
// Created by Vlad on 22-Oct-20.
//

#ifndef ATM_OPERATIONMANAGER_H
#define ATM_OPERATIONMANAGER_H

#include <logics/Customer.h>
#include <logics/bank_services/RegularPayment.h>

class OperationManager {
public:
    bool authorizeCustomer(const QString&, unsigned short);
    void blockCustomer(const QString&);
    ushort registerCustomer(const QString&, const QString&, uint, QString);

    void replenish(uint);
    void withdraw(unsigned int);
    void transfer(const QString&, uint);

    std::pair<Credit*, int> getAllCredits();
    void takeCredit(const QString&, uint, uint, uint, const QDateTime&, const QDateTime&);
    void repayCredit(uint id);

    std::pair<Deposit*, int> getAllDeposits();
    void startDeposit(const QString&, uint, uint, const QDateTime&, const QDateTime&, double);
    void cancelDeposit(uint);
    void replenishDeposit(uint, uint);
    int endDeposit();

    std::pair<RegularPayment*, int> getAllPayments();
    void setPayment(const QString&, uint, const QString&, const QDateTime&);
    void cancelPayment(uint id);
};


#endif //ATM_OPERATIONMANAGER_H
