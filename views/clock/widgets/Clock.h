//
// Created by Iron Tony on 21/10/2020.
//

#ifndef ATM_CLOCK_H
#define ATM_CLOCK_H

#include <QLCDNumber>
#include <QDateTime>

class Clock : public QLCDNumber {
Q_OBJECT

public:
    explicit Clock(QWidget* parent = nullptr);

protected:
    void mouseDoubleClickEvent(QMouseEvent* event) override;

private slots:
    void showDateTime();

private:
    QDateTime* _custom = nullptr;

    void displayTime(const QDateTime&);
};


#endif //ATM_CLOCK_H
