#include "views/main/MainWindow.h"

#include <QApplication>
#include <QtWidgets/QStyleFactory>
#include<QDebug>
#include <QStyle>
#include <logics/auth/Registrator.h>
#include <logics/bank_services/Credit.h>

#include "../ATM/data_access/CreditDAO.h"
#include <QtSql>
//#include <QSqlDatabase>
#include <QMessageBox>
#include <iostream>

int main(int argc, char* argv[]) {
	QApplication a(argc, argv);
	QApplication::setStyle(QStyleFactory::create("Fusion"));
	qDebug() << QApplication::style()->objectName();
	MainWindow w;
	w.show();

	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("../ATM/db_file/bank_database.sqlite");
	if (!db.open()) {
		qDebug() << db.lastError().text();
		return -1;
	}

//	Credit credit("myName", Money(50.23), 0.2, Money(4.90));
//	CreditDAO::getInstance().saveCredit(credit);
//
//	Credit* pCredit = CreditDAO::getInstance().getById(1);
//	std::cout << *pCredit << std::endl;
//	delete pCredit;
//
//	QList<Credit*> credits = CreditDAO::getInstance().getAll();
//	for (auto cred : credits) {
//		std::cout << *cred << std::endl;
//	}
//
//	credit.setName("updated name");
//	if (!CreditDAO::getInstance().updateCredit(credit))
//		qDebug() << "failed to update";
//
//	CreditDAO::getInstance().deleteById(1);

	return QApplication::exec();
}
