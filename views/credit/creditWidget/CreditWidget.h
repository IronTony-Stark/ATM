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

    std::tuple<QString, uint, uint, uint, QDateTime, QDateTime> data();
    void setup(const Credit&);
    void setReadOnly(bool);
    void clear();

private slots:
    void onPeriodChanged();

private:
    Ui::CreditWidget* _ui;
};

#endif // ATM_CREDITWIDGET_H
