//
// Created by Iron Tony on 20/10/2020.
//

#ifndef ATM_CREDITWIDGET_H
#define ATM_CREDITWIDGET_H

#include <QWidget>

namespace Ui {
    class CreditWidget;
}

class CreditWidget : public QWidget {
Q_OBJECT

public:
    explicit CreditWidget(QWidget* parent = nullptr);
    ~CreditWidget() override;

    std::tuple<QString, uint, uint, QDateTime, QDateTime> data();

private:
    Ui::CreditWidget* _ui;
};

#endif // ATM_CREDITWIDGET_H
