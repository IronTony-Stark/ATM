//
// Created by Iron Tony on 20/10/2020.
//

#include "CreditWidget.h"
#include "gui/ui_creditwidget.h"

CreditWidget::CreditWidget(QWidget* parent) :
        QWidget(parent), _ui(new Ui::CreditWidget) {
    _ui->setupUi(this);
}

CreditWidget::~CreditWidget() {
    delete _ui;
}
