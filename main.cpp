#include "views/main/MainWindow.h"

#include <QApplication>
#include <QtWidgets/QStyleFactory>
#include <QDebug>
#include <QStyle>
#include <QtSql>
#include <QtTest/qtestcase.h>
#include <tests/Test_CardDAO.h>
#include <tests/Test_CreditDAO.h>
#include <tests/Test_CustomerDAO.h>
#include <tests/Test_DepositDAO.h>
#include "logics/auth/Registrator.h"
#include "data_access/CreditDAO.h"
#include "data_access/DepositDAO.h"
#include "data_access/CardDAO.h"
#include "data_access/PaymentDAO.h"

int main(int argc, char* argv[]) {
    // ! - HAVE TO BE DONE
    //
    // *Tony*
    // General
    // TODO disable all buttons in left part of interface
    // ! TODO Add info about commissions to the 'Info' tab
    // Transactions
    // ! TODO Update card balance after operations (transfer)
    // Credit
    // ! TODO after pay for credit return to previous page
    // TODO After take credit show popup with sum added to the card (credit body)
    // TODO add credit repayment sum ('payment') to 'Repay Credit' window
    // Deposits
    // ! TODO Deposit end date incorrect (start is shown)
    // ! TODO Deposit interest is 0 (have to be not)
    // ! TODO OpenDepositCommand::execute() pass 0 as percentage
    // TODO Update sum in deposit view after replenish
    // TODO Clear fields in deposit view after return to previous screen

    // *Andrew*
    // ! TODO Make columns belong to Money in 'credit' table accept double
    // ! TODO Add start sum to deposit
    // ! TODO use start sum at CustomerDataM::closeDep(), as deposit has cancelled

	QApplication a(argc, argv);
	QApplication::setStyle(QStyleFactory::create("Fusion"));
	qDebug() << QApplication::style()->objectName();
    MainWindow w;
	w.show();

	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("../MOOP_ATM/db_file/bank_database.sqlite");
	if (!db.open()) {
		qDebug() << db.lastError().text();
		return -1;
	} else {
		// trigger initializations after the db connection is established
		CardDAO::getInstance();
		CreditDAO::getInstance();
		DepositDAO::getInstance();
		CustomerDAO::getInstance();
		PaymentDAO::getInstance();
	}

	freopen("testing.log", "w", stdout);
	QTest::qExec(new Test_CardDAO, argc, argv);
	QTest::qExec(new Test_CreditDAO, argc, argv);
    QTest::qExec(new Test_DepositDAO, argc, argv);
    QTest::qExec(new Test_CustomerDAO, argc, argv);

	// tests/demo
	/*
	RegularPayment payment("important payment", 50, "Vasyl'", "Petro", 20);
	PaymentDAO::getInstance().save(payment);
	QList<RegularPayment*> col = PaymentDAO::getInstance().getAll();
	auto* res = PaymentDAO::getInstance().getById(1);
	PaymentDAO::getInstance().removePayment(1);
	*/

	return QApplication::exec();
}
