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
#include <views/clock/widgets/Clock.h>

class TimeDrivenEventsHandler;

class OperationManager {
private:
    CustomerDataManager _customerDataManager;
    const Authorizer _authorizer;
    const Registrator _registrator;

    const CreditDAO _creditDao;
    const DepositDAO _depositDao;
    const PaymentDAO _paymentDao;
    const CustomerDAO _customerDao;

    Clock* _clock = nullptr;
    TimeDrivenEventsHandler* _timeDrivenEventsHandler = nullptr;

public:
    OperationManager(CustomerDataManager manager);

	bool authorizeCustomer(const QString&, const QString&);

	void blockCustomer(const QString&);

	// pinCode
	QString registerCustomer(const CustomerVerificationData&);

	//static void replenish(const QString& cardNumber, const Money&);
	void replenish(uint);

    //static void withdraw(const QString& cardNumber, const Money&);
	void withdraw(unsigned int);

    static void transfer(const QString&, const QString&, const Money&);
	void transfer(const QString&, uint);

	QList<Credit*> getAllCredits();

	void takeCredit(const QString&, uint, uint, uint, const QDateTime&, const QDateTime&);

	void repayCredit(uint id);

	QList<Deposit*> getAllDeposits();

	void startDeposit(const QString&, uint, uint, const QDateTime&, const QDateTime&, double);

	void cancelDeposit(uint);

	void replenishDeposit(uint, uint);

	int endDeposit(uint);

	QList<RegularPayment*> getAllPayments();
    void setPayment(const QString&, uint, const QString&, const QDateTime&);
    void cancelPayment(uint id);

    void setClock(Clock*);
};


#endif //ATM_OPERATIONMANAGER_H
