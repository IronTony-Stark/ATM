//
// Created by Iron Tony on 20/10/2020.
//

#include "CreditWindow.h"
#include "gui/ui_creditwindow.h"

CreditWindow::CreditWindow(QWidget* parent) :
        QWidget(parent), _ui(new Ui::CreditWindow) {
    _ui->setupUi(this);
}

CreditWindow::~CreditWindow() {
    delete _ui;
}
