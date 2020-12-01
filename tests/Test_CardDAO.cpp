////
//// Created by Andrew on 27-Nov-20.
////
//
//#include <data_access/CardDAO.h>
//#include <QTest>
//#include "Test_CardDAO.h"
//
//void Test_CardDAO::test() {
//    Card* card = new Card(QString("47"), ABankFee::CardType(0), QString("0000"));
//	CardDAO::getInstance().saveCard(*card);
//	Card* restored = CardDAO::getInstance().getById(card->id());
//	compareCards(*restored, *card);
//
//	restored->replenishFree(Money(500));
//    Money old = restored->balance();
//	CardDAO::getInstance().updateCard(*restored);
//	delete restored;
//	restored = CardDAO::getInstance().getById(card->id());
//	QCOMPARE(restored->balance(), old);
//	delete restored;
//
//    CardDAO::getInstance().deleteById("47");
//	restored = CardDAO::getInstance().getById(card->id());
//	QCOMPARE(restored, nullptr);
//}
//
//void Test_CardDAO::compareCards(const Card& actual, const Card& expected) {
//	QCOMPARE(actual.id(), expected.id());
//	QCOMPARE(actual.pin(), expected.pin());
//	QCOMPARE(actual.balance(), expected.balance() );
//	QCOMPARE(actual.isBlocked(), expected.isBlocked());
//}
