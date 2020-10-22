//
// Created by Iron Tony on 20/10/2020.
//

#include "DepositWindow.h"
#include "gui/ui_depositwindow.h"

DepositWindow::DepositWindow(QWidget* parent) :
        QWidget(parent), _ui(new Ui::DepositWindow) {
    _ui->setupUi(this);

    connect(_ui->btnOpenDeposit, &QPushButton::clicked,
            this, &DepositWindow::onBtnOpenDepositClicked);
    connect(_ui->btnMyDeposits, &QPushButton::clicked,
            this, &DepositWindow::onBtnMyDepositsClicked);

    connect(_ui->btnOpenDepositOpen, &QPushButton::clicked,
            this, &DepositWindow::onBtnOpenDepositOpen);
    connect(_ui->btnMyDepositReplenish, &QPushButton::clicked,
            this, &DepositWindow::onBtnMyDepositsReplenishClicked);

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
    _ui->stackedWidget->setCurrentIndex(0);
}

void DepositWindow::onBtnMyDepositsReplenishClicked() {
    _ui->stackedWidget->setCurrentIndex(4);
}

void DepositWindow::onListDepositsItemClicked(QListWidgetItem*) {
    _ui->stackedWidget->setCurrentIndex(3);
}

void DepositWindow::onBtnReplenishSubmit() {
    _ui->stackedWidget->setCurrentIndex(3);
}

void DepositWindow::onBtnReplenishCancel() {
    _ui->stackedWidget->setCurrentIndex(3);
}

void DepositWindow::setupListDeposits() {
    new QListWidgetItem("Deposit 1", _ui->listDeposits);
    new QListWidgetItem("Deposit 2", _ui->listDeposits);
    new QListWidgetItem("Deposit 3", _ui->listDeposits);

    connect(_ui->listDeposits, &QListWidget::itemClicked,
            this, &DepositWindow::onListDepositsItemClicked);
}

void DepositWindow::setController(ControllerLogicSettable* logicSettable) {
    _logicSettable = logicSettable;
}

void DepositWindow::setLogicActive() {
    _logicSettable->setLogic(this);
}
