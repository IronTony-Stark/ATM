//
// Created by Vladyslav Synytsyn on 22-Oct-20.
//

#ifndef ATM_OPERATIONMANAGER_H
#define ATM_OPERATIONMANAGER_H

#include <logics/Customer.h>
#include <logics/bank_services/RegularPayment.h>

#include <logics/utils/TimeDrivenEventsHandler.h>
#include <logics/auth/CustomerVerificationData.h>
#include <logics/auth/Authorizer.h>
#include <logics/auth/Registrator.h>
#include "CustomerDataManager.h"
#include <logics/Customer.h>
#include <data_access/CustomerDAO.h>
#include <data_access/CreditDAO.h>
#include <data_access/DepositDAO.h>
#include <data_access/PaymentDAO.h>

class OperationManager {
private:
    CustomerDataManager _customerDataManager;
    const TimeDrivenEventsHandler _timeDrivenEventsHandler;
    const Authorizer _authorizer;
    const Registrator _registrator;

    const CreditDAO _creditDao;
    const DepositDAO _depositDao;
    const PaymentDAO _paymentDao;

public:

    OperationManager(
            CustomerDataManager manager,
            const TimeDrivenEventsHandler handler,
            const CustomerDAO customerDao,
            const CreditDAO creditDao, const DepositDAO depositDao, const PaymentDAO paymentDao);

    bool authorizeCustomer(const QString&, unsigned short);
    void blockCustomer(const QString&);
    // pinCode
    ushort registerCustomer(const CustomerVerificationData&);

    void replenish(uint);
    void withdraw(unsigned int);
    void transfer(const QString&, uint);

    QList<Credit* const> getAllCredits();
    void takeCredit(const QString&, uint, uint, uint, const QDateTime&, const QDateTime&);
    void repayCredit(uint id);

    QList<Deposit* const> getAllDeposits();
    void startDeposit(const QString&, uint, uint, const QDateTime&, const QDateTime&, double);
    void cancelDeposit(uint);
    void replenishDeposit(uint, uint);

    int endDeposit() { return -1; };

    QList<RegularPayment* const> getAllPayments();
    void setPayment(const QString&, uint, const QString&, const QDateTime&);
    void cancelPayment(uint id);
};


#endif //ATM_OPERATIONMANAGER_H
