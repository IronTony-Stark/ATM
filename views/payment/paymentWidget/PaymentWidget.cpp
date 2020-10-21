//
// Created by Iron Tony on 20/10/2020.
//

#include "PaymentWidget.h"
#include "gui/ui_paymentwidget.h"

PaymentWidget::PaymentWidget(QWidget* parent) :
        QWidget(parent), _ui(new Ui::PaymentWidget) {
    _ui->setupUi(this);
}

PaymentWidget::~PaymentWidget() {
    delete _ui;
}
