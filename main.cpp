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

//    Credit credit("myName", Money(50.23), 0.1, Money(4.90));
//    CreditDAO::getInstance().saveCredit(credit);

	return QApplication::exec();
}
