//
// Created by Iron Tony on 20/10/2020.
//

#include "MainMenuWindow.h"
#include "gui/ui_mainmenuwindow.h"

MainMenuWindow::MainMenuWindow(QWidget* parent) :
        QWidget(parent), _ui(new Ui::MainMenuWindow) {
    _ui->setupUi(this);

    _ui->stackedWidget->addWidget(&_transactionWindow);
    _ui->stackedWidget->addWidget(&_creditWindow);
    _ui->stackedWidget->addWidget(&_depositWindow);
    _ui->stackedWidget->addWidget(&_paymentWindow);

    connect(_ui->btnTransaction, &QPushButton::clicked,
            this, &MainMenuWindow::onBtnTransactionClicked);
    connect(_ui->btnCredit, &QPushButton::clicked,
            this, &MainMenuWindow::onBtnCreditClicked);
    connect(_ui->btnDeposit, &QPushButton::clicked,
            this, &MainMenuWindow::onBtnDepositClicked);
    connect(_ui->btnPayment, &QPushButton::clicked,
            this, &MainMenuWindow::onBtnPaymentClicked);

    connect(&_transactionWindow, &TransactionWindow::signalBtnBackToMainMenuClicked,
            this, &MainMenuWindow::onBtnBackToMainMenuClicked);
    connect(&_creditWindow, &CreditWindow::signalBtnBackToMainMenuClicked,
            this, &MainMenuWindow::onBtnBackToMainMenuClicked);
    connect(&_depositWindow, &DepositWindow::signalBtnBackToMainMenuClicked,
            this, &MainMenuWindow::onBtnBackToMainMenuClicked);
    connect(&_paymentWindow, &PaymentWindow::signalBtnBackToMainMenuClicked,
            this, &MainMenuWindow::onBtnBackToMainMenuClicked);

    connect(_ui->btnFinish, &QPushButton::clicked,
            this, &MainMenuWindow::onBtnFinishClicked);
}

MainMenuWindow::~MainMenuWindow() {
    delete _ui;
}

void MainMenuWindow::onBtnTransactionClicked() {
    _ui->stackedWidget->setCurrentIndex(1);
}

void MainMenuWindow::onBtnCreditClicked() {
    _ui->stackedWidget->setCurrentIndex(2);
}

void MainMenuWindow::onBtnDepositClicked() {
    _ui->stackedWidget->setCurrentIndex(3);
}

void MainMenuWindow::onBtnPaymentClicked() {
    _ui->stackedWidget->setCurrentIndex(4);
}

void MainMenuWindow::onBtnBackToMainMenuClicked() {
    _ui->stackedWidget->setCurrentIndex(0);
}

void MainMenuWindow::onBtnFinishClicked() {
    emit signalBtnFinishClicked();
}

void MainMenuWindow::setController(ControllerLogicSettable* logicSettable) {
    _logicSettable = logicSettable;
    _transactionWindow.setController(logicSettable);
    _creditWindow.setController(logicSettable);
    _depositWindow.setController(logicSettable);
    _paymentWindow.setController(logicSettable);
}
