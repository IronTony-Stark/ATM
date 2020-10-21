//
// Created by Iron Tony on 20/10/2020.
//

#include "DepositWidget.h"
#include "gui/ui_depositwidget.h"

DepositWidget::DepositWidget(QWidget* parent) :
        QWidget(parent), _ui(new Ui::DepositWidget) {
    _ui->setupUi(this);
}

DepositWidget::~DepositWidget() {
    delete _ui;
}
