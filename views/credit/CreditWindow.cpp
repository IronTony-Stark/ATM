//
// Created by Iron Tony on 20/10/2020.
//

#include "CreditWindow.h"
#include "gui/ui_creditwindow.h"

CreditWindow::CreditWindow(QWidget* parent) :
        QWidget(parent), _ui(new Ui::CreditWindow) {
    _ui->setupUi(this);

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
    _ui->stackedWidget->setCurrentIndex(0);
}

void CreditWindow::onBtnBackToCreditMenuClicked() {
    _ui->stackedWidget->setCurrentIndex(0);
}

void CreditWindow::onBtnBackToMyCreditsClicked() {
    _ui->stackedWidget->setCurrentIndex(2);
}

void CreditWindow::setupListCredits() {
    new QListWidgetItem("Credit 1", _ui->listCredits);
    new QListWidgetItem("Credit 2", _ui->listCredits);
    new QListWidgetItem("Credit 3", _ui->listCredits);

    connect(_ui->listCredits, &QListWidget::itemClicked,
            this, &CreditWindow::onListCreditsItemClicked);
}

void CreditWindow::onListCreditsItemClicked(QListWidgetItem*) {
    _ui->stackedWidget->setCurrentIndex(3);
}

void CreditWindow::setController(ControllerLogicSettable* logicSettable) {
    _logicSettable = logicSettable;
}

