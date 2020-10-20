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
    _stackedWidget->setCurrentIndex(2);
}