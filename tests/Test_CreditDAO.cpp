////
//// Created by Andrew on 27-Nov-20.
////
//
//#include <data_access/CreditDAO.h>
//#include <QTest>
//#include "Test_CreditDAO.h"
//
//void Test_CreditDAO::test() {
//    Credit* credit = new Credit("testCreditName", Money(50.25), 0.16, Money(4.90));
//	CreditDAO::getInstance().saveCredit(*credit);
//
//	Credit* pCredit = CreditDAO::getInstance().getById(credit->id());
//	compareCredits(*pCredit, *credit);
//
//	credit->setName("updated testing name");
//	CreditDAO::getInstance().updateCredit(*credit);
//	delete pCredit;
//
//	pCredit = CreditDAO::getInstance().getById(credit->id());
//	QCOMPARE(pCredit->name(), credit->name());
//
//	CreditDAO::getInstance().deleteById(credit->id());
//	delete pCredit;
//	pCredit = CreditDAO::getInstance().getById(credit->id());
//	QCOMPARE(pCredit, nullptr);
//	delete credit;
//}
//
//void Test_CreditDAO::compareCredits(const Credit& actual, const Credit& expected) {
//	QCOMPARE(actual.name(), expected.name());
//	QCOMPARE(actual.creditBody(), expected.creditBody());
//	QCOMPARE(actual.interest(), expected.interest());
//	QCOMPARE(actual.payment(), expected.payment());
//}
