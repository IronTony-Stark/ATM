//
// Created by Iron Tony on 20/10/2020.
//

#include "SetDialog.h"
#include "gui/ui_setdialog.h"

SetDialog::SetDialog(QWidget* parent) :
        QDialog(parent), _ui(new Ui::SetDialog) {
    _ui->setupUi(this);

    connect(_ui->btnSet, &QPushButton::clicked,
            this, &SetDialog::accept);
    connect(_ui->btnCancel, &QPushButton::clicked,
            this, &SetDialog::reject);
}

SetDialog::~SetDialog() {
    delete _ui;
}

QTime SetDialog::getTime() {
    return _ui->editTime->time();
}

QDate SetDialog::getDate() {
    return _ui->editDate->date();
}

void SetDialog::setDateTime(const QDateTime& dateTime) {
    _ui->editDate->setDate(dateTime.date());
    _ui->editTime->setTime(dateTime.time());
}



