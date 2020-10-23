//
// Created by Iron Tony on 20/10/2020.
//

#include <QtWidgets/QMessageBox>
#include "CreditWindow.h"
#include "gui/ui_creditwindow.h"

CreditWindow::CreditWindow(OperationManager& operationManager, QWidget* parent) :
        QWidget(parent), _ui(new Ui::CreditWindow),
        _operationManager(operationManager) {
    _ui->setupUi(this);

    _ui->labelTakeCreditLimit->setText(QString::number(Credit::creditLimitOfIncome));

    connect(_ui->btnTakeCredit, &QPushButton::clicked,
            this, &CreditWindow::onBtnTakeCreditClicked);
    connect(_ui->btnMyCredits, &QPushButton::clicked,
            this, &CreditWindow::onBtnMyCreditsClicked);

    connect(_ui->btnTakeCreditSubmit, &QPushButton::clicked,
            this, &CreditWindow::onBtnTakeCreditSubmitClicked);
    connect(_ui->btnTakeCreditCancel, &QPushButton::clicked,
            this, &CreditWindow::onBtnBackToCreditMenuClicked);
    connect(_ui->btnMyCreditsBack, &QPushButton::clicked,
            this, &CreditWindow::onBtnBackToCreditMenuClicked);

    connect(_ui->btnMyCreditRepay, &QPushButton::clicked,
            this, &CreditWindow::onBtnMyCreditRepayClicked);
    connect(_ui->btnMyCreditBack, &QPushButton::clicked,
            this, &CreditWindow::onBtnBackToMyCreditsClicked);

    connect(_ui->btnBackToMainMenu, &QPushButton::clicked,
            this, &CreditWindow::onBtnBackToMainMenuClicked);

    setupListCredits();
}

CreditWindow::~CreditWindow() {
    delete _ui;
}

void CreditWindow::onBtnBackToMainMenuClicked() {
    emit signalBtnBackToMainMenuClicked();
}

void CreditWindow::onBtnTakeCreditClicked() {
    _ui->stackedWidget->setCurrentIndex(1);
}

void CreditWindow::onBtnMyCreditsClicked() {
    _ui->stackedWidget->setCurrentIndex(2);
}

void CreditWindow::onBtnTakeCreditSubmitClicked() {
    QString name;
    uint sum;
    uint period;
    uint payment;
    QDateTime start;
    QDateTime end;
    std::tie(name, sum, period, payment, start, end) = _ui->widgetTakeCreditCredit->data();
    try {
        _operationManager.takeCredit(name, sum, period, payment, start, end);
        _ui->stackedWidget->setCurrentIndex(0);
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "ATM", e.what());
    }
}

void CreditWindow::onBtnBackToCreditMenuClicked() {
    _ui->stackedWidget->setCurrentIndex(0);
}

void CreditWindow::onBtnBackToMyCreditsClicked() {
    _ui->stackedWidget->setCurrentIndex(2);
}

// TODO credit name
void CreditWindow::setupListCredits() {
    // TODO credits
//    std::pair<Credit*, int> credits = _operationManager.getAllCredits();
//    delete[] _credits;
//    _credits = credits.first;
//    _creditsLen = credits.second;
//
//    for (int i = 0; i < _creditsLen; ++i) {
//        new QListWidgetItem(QString::number(i), _ui->listCredits);
//    }

    connect(_ui->listCredits, &QListWidget::itemClicked,
            this, &CreditWindow::onListCreditsItemClicked);
}

void CreditWindow::onListCreditsItemClicked(QListWidgetItem* item) {
    int index = _ui->listCredits->row(item);
    _selectedCredit = index;
    Credit& credit = _credits[index];
    setupCreditItem(credit);
    _ui->stackedWidget->setCurrentIndex(3);
}

void CreditWindow::setController(ControllerLogicSettable* logicSettable) {
    _logicSettable = logicSettable;
}

void CreditWindow::setLogicActive() {
    _logicSettable->setLogic(this);
}

// TODO credit item
void CreditWindow::setupCreditItem(Credit&) {

}

// TODO pass id
void CreditWindow::onBtnMyCreditRepayClicked() {
    try {
        _operationManager.repayCredit(-1);
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "ATM", e.what());
    }
}
