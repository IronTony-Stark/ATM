//
// Created by Iron Tony on 20/10/2020.
//

#include "MainMenuWindow.h"
#include "gui/ui_mainmenuwindow.h"

enum Windows {
    MAIN_MENU,
    TRANSACTION,
    CREDIT,
    DEPOSIT,
    PAYMENT,
};

MainMenuWindow::MainMenuWindow(OperationManager& operationManager, QWidget* parent) :
        QWidget(parent), _ui(new Ui::MainMenuWindow),
        _operationManager(operationManager),
        _transactionWindow(operationManager),
        _creditWindow(operationManager),
        _depositWindow(operationManager),
        _paymentWindow(operationManager) {
    _ui->setupUi(this);

    _ui->stackedWidget->addWidget(&_transactionWindow);
    _ui->stackedWidget->addWidget(&_creditWindow);
    _ui->stackedWidget->addWidget(&_depositWindow);
    _ui->stackedWidget->addWidget(&_paymentWindow);

    connect(&_transactionWindow, &TransactionWindow::signalBtnBackToMainMenuClicked,
            this, &MainMenuWindow::onBtnBackToMainMenuClicked);
    connect(&_creditWindow, &CreditWindow::signalBtnBackToMainMenuClicked,
            this, &MainMenuWindow::onBtnBackToMainMenuClicked);
    connect(&_depositWindow, &DepositWindow::signalBtnBackToMainMenuClicked,
            this, &MainMenuWindow::onBtnBackToMainMenuClicked);
    connect(&_paymentWindow, &PaymentWindow::signalBtnBackToMainMenuClicked,
            this, &MainMenuWindow::onBtnBackToMainMenuClicked);
}

MainMenuWindow::~MainMenuWindow() {
    delete _ui;
}

void MainMenuWindow::setController(ControllerLogicSettable* logicSettable) {
    _logicSettable = logicSettable;
    _transactionWindow.setController(logicSettable);
    _creditWindow.setController(logicSettable);
    _depositWindow.setController(logicSettable);
    _paymentWindow.setController(logicSettable);
}

void MainMenuWindow::setLogicActive() {
    _logicSettable->setLogic(this);
    double balance = static_cast<double>(_operationManager.getInsertedCardBalance());
    _ui->labelBalanceValue->setText(QString::number(balance));
}

void MainMenuWindow::onBtnCancelClicked() {
    emit signalBtnFinishClicked();
}

void MainMenuWindow::onBtn0Clicked() {
    _transactionWindow.setLogicActive();
    _ui->stackedWidget->setCurrentIndex(TRANSACTION);
}

void MainMenuWindow::onBtn1Clicked() {
    _creditWindow.setLogicActive();
    _ui->stackedWidget->setCurrentIndex(CREDIT);
}

void MainMenuWindow::onBtn2Clicked() {
    _depositWindow.setLogicActive();
    _ui->stackedWidget->setCurrentIndex(DEPOSIT);
}

void MainMenuWindow::onBtn3Clicked() {
    _paymentWindow.setLogicActive();
    _ui->stackedWidget->setCurrentIndex(PAYMENT);
}

void MainMenuWindow::onBtnBackToMainMenuClicked() {
    setLogicActive();
    _ui->stackedWidget->setCurrentIndex(MAIN_MENU);
}
