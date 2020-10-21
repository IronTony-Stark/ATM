//
// Created by Iron Tony on 20/10/2020.
//

#include "StartWindow.h"
#include "gui/ui_startwindow.h"

StartWindow::StartWindow(QWidget* parent) :
        QWidget(parent), _ui(new Ui::StartWindow) {
    _ui->setupUi(this);

    _ui->stackedWidget->addWidget(&_registrationWindow);
    _ui->stackedWidget->addWidget(&_mainMenuWindow);

    connect(_ui->btnInfo, &QPushButton::clicked,
            this, &StartWindow::onBtnInfoClicked);

    connect(_ui->btnRegister, &QPushButton::clicked,
            this, &StartWindow::onBtnRegisterClicked);

    connect(_ui->btnInsertCard, &QPushButton::clicked,
            this, &StartWindow::onBtnInsertCardClicked);

    connect(_ui->btnEnterPin, &QPushButton::clicked,
            this, &StartWindow::onBtnEnterPinClicked);

    connect(_ui->btnBack, &QPushButton::clicked,
            this, &StartWindow::onBtnBackClicked);

    connect(&_registrationWindow, &RegistrationWindow::signalBtnCancelClicked,
            this, &StartWindow::onBtnBackClicked);

    connect(&_mainMenuWindow, &MainMenuWindow::signalBtnFinishClicked,
            this, &StartWindow::onBtnBackClicked);
}

StartWindow::~StartWindow() {
    delete _ui;
}

void StartWindow::onBtnInfoClicked() {
    _ui->stackedWidget->setCurrentIndex(1);
}

void StartWindow::onBtnBackClicked() {
    _ui->stackedWidget->setCurrentIndex(0);
}

void StartWindow::onBtnRegisterClicked() {
    _ui->stackedWidget->setCurrentIndex(3);
}

void StartWindow::onBtnInsertCardClicked() {
    _ui->stackedWidget->setCurrentIndex(2);
}

void StartWindow::onBtnEnterPinClicked() {
    _ui->stackedWidget->setCurrentIndex(4);
}