//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_PAYMENTWIDGET_H
#define ATM_PAYMENTWIDGET_H

#include <QWidget>

namespace Ui {
    class PaymentWidget;
}

class PaymentWidget : public QWidget {
Q_OBJECT

public:
    explicit PaymentWidget(QWidget* parent = nullptr);
    ~PaymentWidget() override;

    std::tuple<QString, uint, QString, QDateTime> data();

    bool validateInput();

private:
    Ui::PaymentWidget* _ui;
};

#endif // ATM_PAYMENTWIDGET_H
