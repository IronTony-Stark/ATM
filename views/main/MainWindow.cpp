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
    connect(_ui->btnClear, &QPushButton::clicked,
            this, &MainWindow::onBtnClearClicked);
    connect(_ui->btn0, &QPushButton::clicked,
            this, &MainWindow::onBtn0Clicked);
    connect(_ui->btn1, &QPushButton::clicked,
            this, &MainWindow::onBtn1Clicked);
    connect(_ui->btn2, &QPushButton::clicked,
            this, &MainWindow::onBtn2Clicked);
    connect(_ui->btn3, &QPushButton::clicked,
            this, &MainWindow::onBtn3Clicked);
    connect(_ui->btn4, &QPushButton::clicked,
            this, &MainWindow::onBtn4Clicked);
    connect(_ui->btn5, &QPushButton::clicked,
            this, &MainWindow::onBtn5Clicked);
    connect(_ui->btn6, &QPushButton::clicked,
            this, &MainWindow::onBtn6Clicked);
    connect(_ui->btn7, &QPushButton::clicked,
            this, &MainWindow::onBtn7Clicked);
    connect(_ui->btn8, &QPushButton::clicked,
            this, &MainWindow::onBtn8Clicked);
    connect(_ui->btn9, &QPushButton::clicked,
            this, &MainWindow::onBtn9Clicked);
    connect(_ui->btnMoneyIn, &QPushButton::clicked,
            this, &MainWindow::onBtnMoneyInClicked);
    connect(_ui->btnCheck, &QPushButton::clicked,
            this, &MainWindow::onBtnCheckClicked);
    connect(_ui->btnCard, &QPushButton::clicked,
            this, &MainWindow::onBtnCardClicked);
    connect(_ui->btnPoint, &QPushButton::clicked,
            this, &MainWindow::onBtnPointClicked);
    connect(_ui->btnMoneyOut, &QPushButton::clicked,
            this, &MainWindow::onBtnMoneyOutClicked);

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
