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
	QApplication a(argc, argv);
//	QApplication::setStyle(QStyleFactory::create("Fusion"));
    MainWindow w;
    w.setWindowTitle("ATM");
	w.show();

    qDebug()  <<  QSqlDatabase::drivers();
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("../db_file/bank_database.sqlite");
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

//	freopen("testing.log", "w", stdout);
//	QTest::qExec(new Test_CardDAO, argc, argv);
//	QTest::qExec(new Test_CreditDAO, argc, argv);
//    QTest::qExec(new Test_DepositDAO, argc, argv);
//    QTest::qExec(new Test_CustomerDAO, argc, argv);

	return QApplication::exec();
}
