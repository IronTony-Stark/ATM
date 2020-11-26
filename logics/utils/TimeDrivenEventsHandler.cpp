//
// Created by Vladyslav Synytsyn on 22/10/2020.
//

#include <data_access/PaymentDAO.h>
#include <data_access/CardDAO.h>
#include "TimeDrivenEventsHandler.h"

#include "QDebug"


void TimeDrivenEventsHandler::payPayments() {
    qDebug() << "Paying for payments";
    const QList<RegularPayment*>& payments = PaymentDAO::getInstance().getAll();
    for (RegularPayment* payment: payments) {
        // TODO check for card was blocked
        if (payment->dayOfMonth() == QDateTime::currentDateTime().date().day()) {
            OperationManager::transfer(payment->sender(), payment->receiver(), payment->amount());
        }
    }
    _isPayed = true;
}

void TimeDrivenEventsHandler::onTimeChanged(const QDateTime& dateTime) {
    if (_isPayed && dateTime.time() <= QTime(0, 1))
        _isPayed = false;
    if (!_isPayed && dateTime.time() >= QTime(10, 0))
        payPayments();
    increaseDeposits(dateTime);
    qDebug() << "click " << dateTime.time().second();
}

void TimeDrivenEventsHandler::increaseDeposits(const QDateTime& dateTime) {
    DepositDAO& depositDao = DepositDAO::getInstance();
    const QList<Deposit*>& deposits = depositDao.getAll();
    qDebug() << "Deposits count: " << deposits.count();
    for (Deposit* deposit: deposits) {
        if (deposit->endDate() <= dateTime.date()) {
            double interestPerSecond = deposit->interest() / 365 / 24 / 3600;
            const Money& incomePerSecond = deposit->sum() * interestPerSecond;
            qDebug() << deposit->name() << incomePerSecond.operator double();
            deposit->replenish(incomePerSecond);
            depositDao.updateDeposit(*deposit);
        }
    }
}
