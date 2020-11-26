//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_SETDIALOG_H
#define ATM_SETDIALOG_H

#include <QDialog>
#include <QTime>
#include <QDate>

namespace Ui {
    class SetDialog;
}

class SetDialog : public QDialog {
Q_OBJECT

public:
    explicit SetDialog(QWidget* parent = nullptr);
    ~SetDialog() override;

    QTime getTime();
    QDate getDate();

    void setDateTime(const QDateTime&);

private:
    Ui::SetDialog* _ui;
};

#endif // ATM_SETDIALOG_H
