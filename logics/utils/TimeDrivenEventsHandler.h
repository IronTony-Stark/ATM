//
// Created by Vladyslav Synytsyn on 22/10/2020.
//

#ifndef ATM_TIME_DRIVEN_EVENTS_HANDLER_H
#define ATM_TIME_DRIVEN_EVENTS_HANDLER_H


#include <QtCore/QArgument>
#include <QtCore/QTimer>
#include <logics/managers/OperationManager.h>
#include <views/clock/widgets/ClockListener.h>

class OperationManager;

class TimeDrivenEventsHandler : public ClockListener {
public:

    TimeDrivenEventsHandler(OperationManager* operationManager) :
            ClockListener(),
            _operationManager(operationManager) {}

    ~TimeDrivenEventsHandler() = default;

    void onTimeChanged(const QDateTime& dateTime) override;

private:
    bool _isPayed = false;
    bool _isIncreased = false;
    OperationManager* _operationManager;

    void payPayments(const QDateTime& dateTime);
    void increaseDeposits(const QDateTime& dateTime);
    static void checkPaymentsDate(const QDateTime& dateTime);
};


#endif //ATM_TIME_DRIVEN_EVENTS_HANDLER_H
