//
// Created by Iron Tony on 20/10/2020.
//

#include "DepositWindow.h"
#include "gui/ui_depositwindow.h"

DepositWindow::DepositWindow(QWidget* parent) :
        QWidget(parent), _ui(new Ui::DepositWindow) {
    _ui->setupUi(this);
}

DepositWindow::~DepositWindow() {
    delete _ui;
}
