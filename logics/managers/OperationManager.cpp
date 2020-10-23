//
// Created by Andrew on 02-Oct-20.
//

#include "OperationManager.h"

// todo withdraw, transfer, register, takeCredit, repayCredit, replenishDeposit, startDeposit can throw std::exception
bool OperationManager::authorizeCustomer(const QString& cardNumber, unsigned short pinCode) {
    return true;
}

void OperationManager::blockCustomer(const QString& cardNumber) {

}

ushort OperationManager::registerCustomer(const QString& name, const QString& phone, uint taxNumber, QString cardType) {
    return 1;
}

void OperationManager::withdraw(unsigned int amount) {

}

int OperationManager::endDeposit() {
    return 0;
}

void OperationManager::setPayment(unsigned long amount, const QDate& date) {

}

void OperationManager::repayCredit(uint id) {

}

void OperationManager::replenish(uint howMuch) {
}

void OperationManager::transfer(const QString& cartNumberFromTo, uint amount) {

}

std::pair<Credit*, int> OperationManager::getAllCredits() {
    return std::make_pair(nullptr, 0);
}

void OperationManager::takeCredit(const QString& name,
                                  uint amount,
                                  uint period,
                                  uint payment,
                                  const QDateTime& start,
                                  const QDateTime& end) {

}

void OperationManager::startDeposit(const QString&, uint, uint, const QDateTime&, const QDateTime&, double) {

}

std::pair<Deposit*, int> OperationManager::getAllDeposits() {
    return std::pair<Deposit*, int>(nullptr, 0);
}

void OperationManager::cancelDeposit(uint id) {

}

void OperationManager::replenishDeposit(uint id, uint amount) {

}




