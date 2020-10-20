//
// Created by Iron Tony on 20/10/2020.
//

#include "MainWindow.h"
#include "gui/ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
        : QMainWindow(parent), _ui(new Ui::MainWindow) {
    _ui->setupUi(this);

    _stackedWidget = _ui->centralwidget->findChild<QStackedWidget*>("stackedWidget");
    _stackedWidget->addWidget(&_registrationWindow);
    _stackedWidget->addWidget(&_mainMenuWindow);
    _stackedWidget->setCurrentIndex(0);

    auto* btnInfo = _ui->centralwidget->findChild<QPushButton*>("btnInfo");
    connect(btnInfo, &QPushButton::clicked,
            this, &MainWindow::onBtnInfoClicked);

    auto* btnBack = _ui->centralwidget->findChild<QPushButton*>("btnBack");
    connect(btnBack, &QPushButton::clicked,
            this, &MainWindow::onBtnBackClicked);

    auto* btnRegister = _ui->centralwidget->findChild<QPushButton*>("btnRegister");
    connect(btnRegister, &QPushButton::clicked,
            this, &MainWindow::onBtnRegisterClicked);

    connect(&_registrationWindow, &RegistrationWindow::signalBtnCancelClicked,
            this, &MainWindow::onBtnBackClicked);

    auto* btnInsertCard = _ui->centralwidget->findChild<QPushButton*>("btnInsertCard");
    connect(btnInsertCard, &QPushButton::clicked,
            this, &MainWindow::onBtnInsertCardClicked);

    auto* btnEnterPin = _ui->centralwidget->findChild<QPushButton*>("btnEnterPin");
    connect(btnEnterPin, &QPushButton::clicked,
            this, &MainWindow::onBtnEnterPinClicked);

    connect(&_mainMenuWindow, &MainMenuWindow::signalBtnFinishClicked,
            this, &MainWindow::onBtnBackClicked);
}

MainWindow::~MainWindow() {
    delete _ui;
}

void MainWindow::onBtnInfoClicked() {
    _stackedWidget->setCurrentIndex(1);
}

void MainWindow::onBtnBackClicked() {
    _stackedWidget->setCurrentIndex(0);
}

void MainWindow::onBtnRegisterClicked() {
    _stackedWidget->setCurrentIndex(3);
}

void MainWindow::onBtnInsertCardClicked() {
    _stackedWidget->setCurrentIndex(2);
}

void MainWindow::onBtnEnterPinClicked() {
    _stackedWidget->setCurrentIndex(4);
}
