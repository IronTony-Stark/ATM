//
// Created by Andrew on 27-Nov-20.
//

#include <logics/Customer.h>
#include <data_access/CustomerDAO.h>
#include <QtTest/qtestcase.h>
#include "Test_CustomerDAO.h"
#include "Test_DepositDAO.h"
#include "Test_CreditDAO.h"
#include "Test_CardDAO.h"

void Test_CustomerDAO::test() {
	Customer* customer = new Customer("CustName", "taxNum", "phoneNum", Money(10.50));
    Card* card = new Card(QString("47"), ABankFee::CardType(0), QString("0000"));
	Credit* credit = new Credit("testCreditName", Money(50.23), 0.2, Money(4.90));
	Deposit* deposit = new Deposit("depo owner", "test deposit name", Money(50.23),
								   0.2, QDate::currentDate().addMonths(5));
	customer->addCard(card);
	customer->addCredit(credit);
	customer->addDeposit(deposit);

	CustomerDAO::getInstance().saveCustomer(*customer);
	Customer* pCustomer = CustomerDAO::getInstance().getById(customer->_taxNumber);
	QCOMPARE(customer->_taxNumber, pCustomer->_taxNumber);
	QCOMPARE(customer->name(), pCustomer->name());
	QCOMPARE(customer->phoneNumber(), pCustomer->phoneNumber());
	QCOMPARE(customer->revenue(), pCustomer->revenue());
    delete pCustomer;

	Test_CardDAO::compareCards(*customer->cards().first(), *card);
	Test_CreditDAO::compareCredits(*customer->credits().first(), *credit);
	Test_DepositDAO::compareDeposits(*customer->deposits().first(), *deposit);

    customer->removeDeposit(deposit->id());
	CustomerDAO::getInstance().removeDeposit(deposit->id());
	customer->setRevenue(5230.85);
	CustomerDAO::getInstance().updateCustomerCore(*customer);
    pCustomer = CustomerDAO::getInstance().getById(customer->_taxNumber);
    QCOMPARE(pCustomer->deposits().length(), 0);
    QCOMPARE(pCustomer->revenue(), customer->revenue());

    CustomerDAO::getInstance().removeCredit(credit->id());
    CustomerDAO::getInstance().removeCard(card->id());
    delete pCustomer;

    CustomerDAO::getInstance().deleteById(customer->_taxNumber);
    pCustomer = CustomerDAO::getInstance().getById(customer->_taxNumber);
    QCOMPARE(pCustomer, nullptr);
    delete customer;
}

