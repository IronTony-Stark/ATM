////
//// Created by Andrew on 27-Nov-20.
////
//
//#include <data_access/DepositDAO.h>
//#include <QTest>
//#include "Test_DepositDAO.h"
//
//void Test_DepositDAO::test() {
//    Deposit* deposit = new Deposit("depo owner", "test deposit name", Money(50.25),
//                                0.16, QDate::currentDate().addMonths(5));
//	DepositDAO::getInstance().saveDeposit(*deposit);
//	Deposit* pDeposit = DepositDAO::getInstance().getById(deposit->id());
//	compareDeposits(*pDeposit, *deposit);
//
//	deposit->replenish(57.65);
//	DepositDAO::getInstance().updateDeposit(*deposit);
//	delete pDeposit;
//	pDeposit = DepositDAO::getInstance().getById(deposit->id());
//	QCOMPARE(pDeposit->sum(), deposit->sum());
//	delete pDeposit;
//
//	DepositDAO::getInstance().deleteById(deposit->id());
//	pDeposit = DepositDAO::getInstance().getById(deposit->id());
//	QCOMPARE(pDeposit, nullptr);
//	delete deposit;
//}
//
//void Test_DepositDAO::compareDeposits(const Deposit& actual, const Deposit& expected) {
//	QCOMPARE(actual.ownerCard(), expected.ownerCard());
//	QCOMPARE(actual.name(), expected.name());
//	QCOMPARE(actual.initBalance(), expected.initBalance());
//	QCOMPARE(actual.sum(), expected.sum());
//	QCOMPARE(actual.interest(), expected.interest());
//	QCOMPARE(actual.startDate(), expected.startDate());
//	QCOMPARE(actual.endDate(), expected.endDate());
//}
