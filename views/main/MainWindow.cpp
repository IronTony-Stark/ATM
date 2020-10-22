//
// Created by Iron Tony on 20/10/2020.
//

#include "MainWindow.h"
#include "gui/ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
        : QMainWindow(parent), _ui(new Ui::MainWindow) {
    _ui->setupUi(this);

    connect(_ui->btnEnter, &QPushButton::clicked,
            this, &MainWindow::onBtnEnterClicked);
    connect(_ui->btnCancel, &QPushButton::clicked,
            this, &MainWindow::onBtnCancelClicked);

    _ui->mainWindow->setController(this);
}

MainWindow::~MainWindow() {
    delete _ui;
}

void MainWindow::setLogic(ControllerLogic* logic) {
    _logic = logic;
}

void MainWindow::onBtnEnterClicked() {
    assert(_logic != nullptr);
    _logic->onBtnEnterClicked();
}

void MainWindow::onBtnCancelClicked() {
    assert(_logic != nullptr);
    _logic->onBtnCancelClicked();
}

void MainWindow::onBtnClearClicked() {
    assert(_logic != nullptr);
    _logic->onBtnClearClicked();
}

void MainWindow::onBtn0Clicked() {
    assert(_logic != nullptr);
    _logic->onBtn0Clicked();
}

void MainWindow::onBtn1Clicked() {
    assert(_logic != nullptr);
    _logic->onBtn1Clicked();
}

void MainWindow::onBtn2Clicked() {
    assert(_logic != nullptr);
    _logic->onBtn2Clicked();
}

void MainWindow::onBtn3Clicked() {
    assert(_logic != nullptr);
    _logic->onBtn3Clicked();
}

void MainWindow::onBtn4Clicked() {
    assert(_logic != nullptr);
    _logic->onBtn4Clicked();
}

void MainWindow::onBtn5Clicked() {
    assert(_logic != nullptr);
    _logic->onBtn5Clicked();
}

void MainWindow::onBtn6Clicked() {
    assert(_logic != nullptr);
    _logic->onBtn6Clicked();
}

void MainWindow::onBtn7Clicked() {
    assert(_logic != nullptr);
    _logic->onBtn7Clicked();
}

void MainWindow::onBtn8Clicked() {
    assert(_logic != nullptr);
    _logic->onBtn8Clicked();
}

void MainWindow::onBtn9Clicked() {
    assert(_logic != nullptr);
    _logic->onBtn9Clicked();
}

void MainWindow::onBtnPointClicked() {
    assert(_logic != nullptr);
    _logic->onBtnPointClicked();
}

void MainWindow::onBtnMoneyInClicked() {
    assert(_logic != nullptr);
    _logic->onBtnMoneyInClicked();
}

void MainWindow::onBtnCheckClicked() {
    assert(_logic != nullptr);
    _logic->onBtnCheckClicked();
}

void MainWindow::onBtnCardClicked() {
    assert(_logic != nullptr);
    _logic->onBtnCardClicked();
}

void MainWindow::onBtnMoneyOutClicked() {
    assert(_logic != nullptr);
    _logic->onBtnMoneyOutClicked();
}
