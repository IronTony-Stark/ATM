#include "views/main/MainWindow.h"

#include <QApplication>
#include <QtWidgets/QStyleFactory>
#include <QDebug>
#include <QStyle>
#include <logics/auth/Registrator.h>
#include <data_access/CreditDAO.h>
#include <QtSql>
#include <data_access/DepositDAO.h>
#include <data_access/CardDAO.h>
#include <data_access/PaymentDAO.h>
#include <iostream>
#include <logics/bank_services/RegularPayment.h>

int main(int argc, char* argv[]) {
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

    // tests/demo
    /*
    Credit* credit = new Credit("myName", Money(50.23), 0.2, Money(4.90));
    CreditDAO::getInstance().saveCredit(*credit);

    Credit* pCredit = CreditDAO::getInstance().getById(1);
    if (pCredit) std::cout << *pCredit << std::endl;
    delete pCredit;

    QList<Credit*> credits = CreditDAO::getInstance().getAll();
    for (auto cred : credits) {
        std::cout << *cred << std::endl;
    }

    credit->setName("updated name");
    if (!CreditDAO::getInstance().updateCredit(*credit))
        qDebug() << "failed to update";

    CreditDAO::getInstance().deleteById(2);


    Deposit* deposit = new Deposit("myName", Money(50.23), 0.2, QDate::currentDate().addMonths(5));
    DepositDAO::getInstance().saveDeposit(*deposit);

    Deposit* pDeposit = DepositDAO::getInstance().getById(1);
    if (pDeposit) std::cout << *pDeposit << std::endl;

    QList<Deposit*> deposits = DepositDAO::getInstance().getAll();
    for (auto dep : deposits) {
        std::cout << *dep << std::endl;
    }

    deposit->setName("updated name");
    if (!DepositDAO::getInstance().updateDeposit(*deposit))
        qDebug() << "failed to update";

    DepositDAO::getInstance().deleteById(1);

    Card* card = new Card(QString("cardCode"), ABankFee::CardType(0), QString("0000"));
    CardDAO::getInstance().saveCard(*card);
    Card* restored = CardDAO::getInstance().getById(card->id());
    restored->replenish(Money(500));
    CardDAO::getInstance().updateCard(*restored);
    CardDAO::getInstance().deleteById("cardCode");

    Customer* customer = new Customer("CustName", "taxNum", "phoneNum", Money(10.50));
    customer->addCard(card);
    customer->addCredit(credit);
    customer->addDeposit(deposit);
    CustomerDAO::getInstance().saveCustomer(*customer);
    CustomerDAO::getInstance().removeDeposit(customer->_taxNumber, 6);
    CustomerDAO::getInstance().addCredit(customer->_taxNumber, 999);
    customer->setName("new Name for customer");
    CustomerDAO::getInstance().updateCustomerCore(*customer);

    RegularPayment payment("important payment", 50, "Vasyl'", "Petro", 20);
    PaymentDAO::getInstance().save(payment);
    QList<RegularPayment*> col = PaymentDAO::getInstance().getAll();
    auto* res = PaymentDAO::getInstance().getById(1);
    PaymentDAO::getInstance().removePayment(1);
    */

    return QApplication::exec();
}
