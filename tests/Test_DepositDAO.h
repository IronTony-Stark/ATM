//
// Created by Andrew on 27-Nov-20.
//

#ifndef MOOP_ATM_TEST_DEPOSITDAO_H
#define MOOP_ATM_TEST_DEPOSITDAO_H


#include <QtCore/QObject>

#include <logics/bank_services/Deposit.h>

class Test_DepositDAO : public QObject {
Q_OBJECT
public:
	explicit Test_DepositDAO(QObject* parent = nullptr) : QObject(parent) {};

	static void compareDeposits(const Deposit& actual, const Deposit& expected);

private slots:

	void test();
};


#endif //MOOP_ATM_TEST_DEPOSITDAO_H
