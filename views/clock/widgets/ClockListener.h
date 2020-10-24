//
// Created by Iron Tony on 24/10/2020.
//

#ifndef ATM_CLOCKLISTENER_H
#define ATM_CLOCKLISTENER_H

#include <QtCore/QDateTime>

class ClockListener {
public:
    virtual void onTimeChanged(const QDateTime& newTime) = 0;

protected:
    ~ClockListener() = default;
};

#endif //ATM_CLOCKLISTENER_H
