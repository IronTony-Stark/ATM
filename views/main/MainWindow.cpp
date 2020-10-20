//
// Created by Iron Tony on 20/10/2020.
//

#include "MainWindow.h"
#include "gui/ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
        : QMainWindow(parent), _ui(new Ui::MainWindow) {
    _ui->setupUi(this);
    _stackedWidget = _ui->centralwidget->findChild<QStackedWidget*>("stackedWidget");
    _stackedWidget->setCurrentIndex(0);

    auto* btnInfo = _ui->centralwidget->findChild<QPushButton*>("btnInfo");
    connect(btnInfo, &QPushButton::clicked, this, &MainWindow::onBtnInfoClicked);

    auto* btnBack = _ui->centralwidget->findChild<QPushButton*>("btnBack");
    connect(btnBack, &QPushButton::clicked, this, &MainWindow::onBtnBack);
}

MainWindow::~MainWindow() {
    delete _ui;
}

void MainWindow::onBtnInfoClicked() {
    _stackedWidget->setCurrentIndex(1);
}

void MainWindow::onBtnBack() {
    _stackedWidget->setCurrentIndex(0);
}
