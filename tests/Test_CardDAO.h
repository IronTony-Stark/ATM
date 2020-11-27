//
// Created by Andrew on 27-Nov-20.
//

#ifndef MOOP_ATM_TEST_CARDDAO_H
#define MOOP_ATM_TEST_CARDDAO_H


#include <QtCore/QObject>

#include <logics/bank_services/Card.h>

class Test_CardDAO : public QObject {
Q_OBJECT
public:
	explicit Test_CardDAO(QObject* parent = nullptr) : QObject(parent) {};

	static void compareCards(const Card& actual, const Card& expected);
private slots:

	void test();
};


#endif //MOOP_ATM_TEST_CARDDAO_H
