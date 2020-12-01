//
// Created by Andrew on 27-Nov-20.
//

#ifndef MOOP_ATM_TEST_CREDITDAO_H
#define MOOP_ATM_TEST_CREDITDAO_H


#include <QtCore/QObject>

#include <logics/bank_services/Credit.h>

class Test_CreditDAO : public QObject {
Q_OBJECT
public:
	explicit Test_CreditDAO(QObject* parent = nullptr) : QObject(parent) {};

	static void compareCredits(const Credit& actual, const Credit& expected);
private slots:

	void test();
};


#endif //MOOP_ATM_TEST_CREDITDAO_H
