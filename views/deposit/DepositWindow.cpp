//
// Created by Iron Tony on 20/10/2020.
//

#include <QtWidgets/QMessageBox>
#include "DepositWindow.h"
#include "gui/ui_depositwindow.h"

DepositWindow::DepositWindow(OperationManager& operationManager, QWidget* parent) :
        QWidget(parent), _ui(new Ui::DepositWindow),
        _operationManager(operationManager) {
    _ui->setupUi(this);

    connect(_ui->btnOpenDeposit, &QPushButton::clicked,
            this, &DepositWindow::onBtnOpenDepositClicked);
    connect(_ui->btnMyDeposits, &QPushButton::clicked,
            this, &DepositWindow::onBtnMyDepositsClicked);

    connect(_ui->btnOpenDepositOpen, &QPushButton::clicked,
            this, &DepositWindow::onBtnOpenDepositOpen);
    connect(_ui->btnMyDepositReplenish, &QPushButton::clicked,
            this, &DepositWindow::onBtnMyDepositsReplenishClicked);

    connect(_ui->btnMyDepositCancel, &QPushButton::clicked,
            this, &DepositWindow::onBtnMyDepositCancelClicked);
    connect(_ui->btnReplenishSubmit, &QPushButton::clicked,
            this, &DepositWindow::onBtnReplenishSubmit);
    connect(_ui->btnReplenishCancel, &QPushButton::clicked,
            this, &DepositWindow::onBtnReplenishCancel);

    connect(_ui->btnOpenDepositCancel, &QPushButton::clicked,
            this, &DepositWindow::onBtnBackToDepositMenuClicked);
    connect(_ui->btnMyDepositsBack, &QPushButton::clicked,
            this, &DepositWindow::onBtnBackToDepositMenuClicked);
    connect(_ui->btnMyDepositBack, &QPushButton::clicked,
            this, &DepositWindow::onBtnBackToMyDepositsClicked);
    connect(_ui->btnBackToMainMenu, &QPushButton::clicked,
            this, &DepositWindow::onBtnBackToMainMenuClicked);

    setupListDeposits();
}

DepositWindow::~DepositWindow() {
    delete _ui;
}

void DepositWindow::onBtnBackToMainMenuClicked() {
    emit signalBtnBackToMainMenuClicked();
}

void DepositWindow::onBtnBackToDepositMenuClicked() {
    _ui->stackedWidget->setCurrentIndex(0);
}

void DepositWindow::onBtnBackToMyDepositsClicked() {
    _ui->stackedWidget->setCurrentIndex(2);
}

void DepositWindow::onBtnMyDepositsClicked() {
    _ui->stackedWidget->setCurrentIndex(2);
}

void DepositWindow::onBtnOpenDepositClicked() {
    _ui->stackedWidget->setCurrentIndex(1);
}

void DepositWindow::onBtnOpenDepositOpen() {
    QString name;
    uint amount;
    uint period;
    QDateTime start;
    QDateTime end;
    uint percentage;
    std::tie(name, amount, period, start, end, percentage) = _ui->widgetOpenDepositDeposit->data();
    try {
        _operationManager.startDeposit(name, amount, period, start, end, percentage);
        _ui->stackedWidget->setCurrentIndex(0);
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "ATM", e.what());
    }
}

void DepositWindow::onBtnMyDepositsReplenishClicked() {
    _ui->stackedWidget->setCurrentIndex(4);
}

void DepositWindow::onListDepositsItemClicked(QListWidgetItem* item) {
    int index = _ui->listDeposits->row(item);
    _selectedDeposit = index;
    Deposit& deposit = _deposits[index];
    setupDepositItem(deposit);
    _ui->stackedWidget->setCurrentIndex(3);
}

// TODO pass deposit id
void DepositWindow::onBtnReplenishSubmit() {
    uint amount = _ui->editReplenishHowMuch->text().toUInt();
    try {
        _operationManager.replenishDeposit(-1, amount);
        _ui->stackedWidget->setCurrentIndex(3);
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "ATM", e.what());
    }
}

void DepositWindow::onBtnReplenishCancel() {
    _ui->stackedWidget->setCurrentIndex(3);
}

void DepositWindow::setupListDeposits() {
    // TODO deposits
//    std::pair<Deposit*, int> deposits = _operationManager.getAllDeposits();
//    delete[] _deposits;
//    _deposits = deposits.first;
//    _depositsLen = deposits.second;
//
//    for (int i = 0; i < _depositsLen; ++i) {
//        new QListWidgetItem(QString::number(i), _ui->listDeposits);
//    }

    connect(_ui->listDeposits, &QListWidget::itemClicked,
            this, &DepositWindow::onListDepositsItemClicked);
}

void DepositWindow::setController(ControllerLogicSettable* logicSettable) {
    _logicSettable = logicSettable;
}

void DepositWindow::setLogicActive() {
    _logicSettable->setLogic(this);
}

void DepositWindow::setupDepositItem(Deposit&) {

}

// TODO pass deposit id
void DepositWindow::onBtnMyDepositCancelClicked() {
    _operationManager.cancelDeposit(-1);
}
