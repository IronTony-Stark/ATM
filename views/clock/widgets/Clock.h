//
// Created by Iron Tony on 21/10/2020.
//

#ifndef ATM_CLOCK_H
#define ATM_CLOCK_H

#include <QLCDNumber>
#include <QDateTime>
#include "ClockListener.h"

class Clock : public QLCDNumber {
Q_OBJECT

public:
    explicit Clock(QWidget* parent = nullptr);

    void subscribe(ClockListener*);
    void unsubscribe(ClockListener*);
    void notifyListeners(const QDateTime&);

protected:
#ifdef QT_DEBUG
    void mouseDoubleClickEvent(QMouseEvent* event) override;
#endif

private slots:
    void showDateTime();

private:
    QDateTime* _custom = nullptr;
    std::list<ClockListener*> _clockListeners;

    void displayTime(const QDateTime&);
};


#endif //ATM_CLOCK_H
