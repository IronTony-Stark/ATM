//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_PAYMENTWINDOW_H
#define ATM_PAYMENTWINDOW_H

#include <QWidget>

namespace Ui {
    class PaymentWindow;
}

class PaymentWindow : public QWidget {
Q_OBJECT

public:
    explicit PaymentWindow(QWidget* parent = nullptr);
    ~PaymentWindow() override;

signals:
    void signalBtnBackToMainMenuClicked();

private slots:
    void onBtnBackToMainMenuClicked();

private:
    Ui::PaymentWindow* _ui;
};

#endif // ATM_PAYMENTWINDOW_H
