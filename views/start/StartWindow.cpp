//
// Created by Iron Tony on 20/10/2020.
//

#include "StartWindow.h"
#include "gui/ui_startwindow.h"

enum Windows {
    START,
    INFO,
    INSERT_CARD,
    REGISTER,
    MAIN_MENU,
};

StartWindow::StartWindow(QWidget* parent) :
        QWidget(parent), _ui(new Ui::StartWindow),
        _operationManager(CustomerDataManager()),
        _registrationWindow(_operationManager),
        _mainMenuWindow(_operationManager) {
    _ui->setupUi(this);

    _ui->stackedWidget->addWidget(&_registrationWindow);
    _ui->stackedWidget->addWidget(&_mainMenuWindow);

    connect(&_registrationWindow, &RegistrationWindow::signalBtnCancelClicked,
            this, &StartWindow::onBtnCancelClicked);
    connect(&_mainMenuWindow, &MainMenuWindow::signalBtnFinishClicked,
            this, &StartWindow::onBtnCancelClicked);
}

StartWindow::~StartWindow() {
    delete _ui;
}

void StartWindow::setController(ControllerLogicSettable* logicSettable) {
    _logicSettable = logicSettable;
    _logicSettable->setLogic(this);
    _registrationWindow.setController(logicSettable);
    _mainMenuWindow.setController(logicSettable);
}

void StartWindow::onBtn0Clicked() {
    if (state() == START) {
        _ui->stackedWidget->setCurrentIndex(INFO);
    }
}

void StartWindow::onBtn1Clicked() {
    if (state() == START) {
        _registrationWindow.setLogicActive();
        _ui->stackedWidget->setCurrentIndex(REGISTER);
    }
}

void StartWindow::onBtnCardClicked() {
    if (state() == START) {
        _ui->stackedWidget->setCurrentIndex(INSERT_CARD);
    }
}

void StartWindow::onBtnEnterClicked() {
    if (state() == INSERT_CARD) {
        QString number = _ui->editCardNumber->text();
        ushort pin = _ui->editPin->text().toUShort();
        if (_operationManager.authorizeCustomer(number, pin)) {
            _mainMenuWindow.setLogicActive();
            _ui->stackedWidget->setCurrentIndex(MAIN_MENU);
        } else if (--_pinAttempts == 0) {
            _operationManager.blockCustomer(number);
        }
    }
}

void StartWindow::onBtnCancelClicked() {
    _logicSettable->setLogic(this);
    _ui->stackedWidget->setCurrentIndex(START);
}

int StartWindow::state() {
    return _ui->stackedWidget->currentIndex();
}

void StartWindow::setClock(Clock* clock) {
    _operationManager.setClock(clock); // TODO remove
}
