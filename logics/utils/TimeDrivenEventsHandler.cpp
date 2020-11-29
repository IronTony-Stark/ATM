//
// Created by Vladyslav Synytsyn on 22/10/2020.
//

#include <data_access/PaymentDAO.h>
#include <data_access/CardDAO.h>
#include "TimeDrivenEventsHandler.h"

#include "QDebug"


void TimeDrivenEventsHandler::payPayments(const QDateTime& dateTime) {
    qDebug() << "Paying for payments";
    const QList<RegularPayment*>& payments = PaymentDAO::getInstance().getAll();
    const CardDAO& cardDao = CardDAO::getInstance();
    for (RegularPayment* payment: payments) {
        Card* senderCard = cardDao.getById(payment->sender());
        Card* receiverCard = cardDao.getById(payment->receiver());
        if (senderCard == nullptr){
            qWarning() << "Card " << payment->sender() << "wasn't found for payment " << payment->id();
        }
        if (receiverCard == nullptr){
            qWarning() << "Card " << payment->receiver() << "wasn't found for payment " << payment->id();
        }
        if (receiverCard == nullptr || senderCard == nullptr)
            continue;

        if (senderCard->isBlocked() || receiverCard->isBlocked()){
            qInfo() << "Skipped payment " << payment->id() << " because of blocked card";
            continue;
        }
        if (payment->dayOfMonth() == dateTime.date().day()) {
            OperationManager::transfer(payment->sender(), payment->receiver(), payment->amount());
        }
    }
    _isPayed = true;
}

void TimeDrivenEventsHandler::onTimeChanged(const QDateTime& dateTime) {
    if (_isPayed && dateTime.time() <= QTime(0, 1))
        _isPayed = false;
    if (dateTime.time().minute() == 1)
        _isIncreased = false;
    if (!_isPayed && dateTime.time() >= QTime(10, 0)) {
        checkPaymentsDate(dateTime);
        payPayments(dateTime);
    }
    if (!_isIncreased && dateTime.time().minute() == 0)
        increaseDeposits(dateTime);
}

void TimeDrivenEventsHandler::increaseDeposits(const QDateTime& dateTime) {
    DepositDAO& depositDao = DepositDAO::getInstance();
    const QList<Deposit*>& deposits = depositDao.getAll();
    qDebug() << "Deposits count: " << deposits.count();
    for (Deposit* deposit: deposits) {
        if (deposit->endDate() > dateTime.date()) {
            double interestPerDay = deposit->interest() / 365;
            const Money& incomePerDay = (double)deposit->sum() * interestPerDay;
            qDebug() << deposit->name() << ": " << (double)incomePerDay;
            deposit->replenish(incomePerDay);
            depositDao.updateDeposit(*deposit);
        } else {
            try {
                OperationManager::endDeposit(deposit->id());
                qInfo() << "Deposit '" << deposit->id() << "' was cancelled";
            } catch (const std::exception& e) {
                qWarning() << e.what();
            }
        }
    }
    _isIncreased = true;
}

void TimeDrivenEventsHandler::checkPaymentsDate(const QDateTime& dateTime) {
    qDebug() << "Checking payments date";
    PaymentDAO& paymentDao = PaymentDAO::getInstance();
    const QList<RegularPayment*>& payments = paymentDao.getAll();
    for (RegularPayment* payment: payments) {
        int daysInMonth = dateTime.date().daysInMonth();
        if (payment->dayOfMonth() > daysInMonth || daysInMonth < 31) {
            payment->setDayOfMonth(31 - daysInMonth);
            paymentDao.removePayment(payment->id());
            paymentDao.save(*payment);
        }
    }
}
