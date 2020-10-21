//
// Created by Iron Tony on 20/10/2020.
//

#include "TransactionWindow.h"
#include "gui/ui_transactionwindow.h"

TransactionWindow::TransactionWindow(QWidget* parent) :
        QWidget(parent), _ui(new Ui::TransactionWindow) {
    _ui->setupUi(this);

    connect(_ui->btnBackToMainMenu, &QPushButton::clicked,
            this, &TransactionWindow::onBtnBackToMainMenuClicked);
}

TransactionWindow::~TransactionWindow() {
    delete _ui;
}

void TransactionWindow::onBtnBackToMainMenuClicked() {
    emit signalBtnBackToMainMenuClicked();
}
