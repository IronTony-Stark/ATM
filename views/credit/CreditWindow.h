//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_CREDITWINDOW_H
#define ATM_CREDITWINDOW_H

#include <QWidget>

namespace Ui {
    class CreditWindow;
}

class CreditWindow : public QWidget {
Q_OBJECT

public:
    explicit CreditWindow(QWidget* parent = nullptr);
    ~CreditWindow() override;

private:
    Ui::CreditWindow* _ui;
};

#endif // ATM_CREDITWINDOW_H
