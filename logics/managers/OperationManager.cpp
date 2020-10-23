//
// Created by Andrew on 02-Oct-20.
//

#include "OperationManager.h"

// todo withdraw, transfer, register, takeCredit, repayCredit can throw std::exception
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

void OperationManager::startDeposit(unsigned int startAmount) {

}

int OperationManager::endDeposit() {
    return 0;
}

void OperationManager::cancelDeposit() {

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
                                  const QDateTime& start,
                                  const QDateTime& end) {

}


