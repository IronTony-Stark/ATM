//
// Created by Iron Tony on 20/10/2020.
//

#include "RegistrationWindow.h"
#include "gui/ui_registrationwindow.h"

enum Windows {
    REGISTRATION,
    CARD
};

RegistrationWindow::RegistrationWindow(QWidget* parent) :
        QWidget(parent), _ui(new Ui::RegistrationWindow) {
    _ui->setupUi(this);
}

RegistrationWindow::~RegistrationWindow() {
    delete _ui;
}

void RegistrationWindow::setController(ControllerLogicSettable* logicSettable) {
    _logicSettable = logicSettable;
}

void RegistrationWindow::setLogicActive() {
    _logicSettable->setLogic(this);
}

void RegistrationWindow::onBtnEnterClicked() {
    if (state() != CARD) {
        _ui->stackedWidget->setCurrentIndex(CARD);
    }
}

void RegistrationWindow::onBtnCancelClicked() {
    if (state() != CARD) {
        emit signalBtnCancelClicked();
    }
}

void RegistrationWindow::onBtnCardClicked() {
    if (state() == CARD) {
        emit signalBtnCancelClicked();
        _ui->stackedWidget->setCurrentIndex(REGISTRATION);
    }
}

int RegistrationWindow::state() {
    return _ui->stackedWidget->currentIndex();
}
