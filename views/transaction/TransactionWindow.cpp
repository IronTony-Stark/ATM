//
// Created by Iron Tony on 20/10/2020.
//

#include "TransactionWindow.h"
#include "gui/ui_transactionwindow.h"

TransactionWindow::TransactionWindow(QWidget* parent) :
        QWidget(parent), _ui(new Ui::TransactionWindow) {
    _ui->setupUi(this);

    connect(_ui->btnReplenish, &QPushButton::clicked,
            this, &TransactionWindow::onBtnReplenishClicked);
    connect(_ui->btnWithdraw, &QPushButton::clicked,
            this, &TransactionWindow::onBtnWithdrawClicked);
    connect(_ui->btnTransfer, &QPushButton::clicked,
            this, &TransactionWindow::onBtnTransferClicked);

    connect(_ui->btnReplenishSubmit, &QPushButton::clicked,
            this, &TransactionWindow::onBtnReplenishSubmitClicked);
    connect(_ui->btnWithdrawSubmit, &QPushButton::clicked,
            this, &TransactionWindow::onBtnWithdrawSubmitClicked);
    connect(_ui->btnTransferSubmit, &QPushButton::clicked,
            this, &TransactionWindow::onBtnTransferSubmitClicked);

    connect(_ui->btnReplenishCancel, &QPushButton::clicked,
            this, &TransactionWindow::onBtnBackToTransactionMenu);
    connect(_ui->btnWithdrawCancel, &QPushButton::clicked,
            this, &TransactionWindow::onBtnBackToTransactionMenu);
    connect(_ui->btnTransferCancel, &QPushButton::clicked,
            this, &TransactionWindow::onBtnBackToTransactionMenu);

    connect(_ui->btnBackToMainMenu, &QPushButton::clicked,
            this, &TransactionWindow::onBtnBackToMainMenuClicked);
}

TransactionWindow::~TransactionWindow() {
    delete _ui;
}

void TransactionWindow::onBtnReplenishClicked() {
    _ui->stackedWidget->setCurrentIndex(1);
}

void TransactionWindow::onBtnWithdrawClicked() {
    _ui->stackedWidget->setCurrentIndex(2);
}

void TransactionWindow::onBtnTransferClicked() {
    _ui->stackedWidget->setCurrentIndex(3);
}

void TransactionWindow::onBtnReplenishSubmitClicked() {
    _ui->stackedWidget->setCurrentIndex(0);
}

void TransactionWindow::onBtnWithdrawSubmitClicked() {
    _ui->stackedWidget->setCurrentIndex(0);
}

void TransactionWindow::onBtnTransferSubmitClicked() {
    _ui->stackedWidget->setCurrentIndex(0);
}

void TransactionWindow::onBtnBackToTransactionMenu() {
    _ui->stackedWidget->setCurrentIndex(0);
}

void TransactionWindow::onBtnBackToMainMenuClicked() {
    emit signalBtnBackToMainMenuClicked();
}

void TransactionWindow::setController(ControllerLogicSettable* logicSettable) {
    _logicSettable = logicSettable;
}

void TransactionWindow::setLogicActive() {
    _logicSettable->setLogic(this);
}
