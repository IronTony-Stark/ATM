//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_TRANSACTIONWINDOW_H
#define ATM_TRANSACTIONWINDOW_H

#include <QWidget>

namespace Ui {
    class TransactionWindow;
}

class TransactionWindow : public QWidget {
Q_OBJECT

public:
    explicit TransactionWindow(QWidget* parent = nullptr);
    ~TransactionWindow() override;

private:
    Ui::TransactionWindow* _ui;
};

#endif // ATM_TRANSACTIONWINDOW_H
