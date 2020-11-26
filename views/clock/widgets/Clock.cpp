//
// Created by Iron Tony on 21/10/2020.
//

#include "Clock.h"
#include "views/clock/setdialog/SetDialog.h"
#include <QTimer>

// TODO if debug enable time set
Clock::Clock(QWidget* parent) : QLCDNumber(parent) {
    setSegmentStyle(Filled);
    setDigitCount(18);

    auto* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Clock::showDateTime);
    timer->start(1000);

    showDateTime();
}

void Clock::showDateTime() {
    if (_custom != nullptr) {
        *_custom = _custom->addSecs(1);
        displayTime(*_custom);
    } else {
        displayTime(QDateTime::currentDateTime());
    }
}

void Clock::mouseDoubleClickEvent(QMouseEvent* event) {
    SetDialog dialog;
    dialog.setDateTime(_custom != nullptr ? *_custom : QDateTime::currentDateTime());
    dialog.setModal(true);
    int result = dialog.exec();
    delete _custom;
    _custom = nullptr;
    if (result == 1) {
        _custom = new QDateTime(dialog.getDate(), dialog.getTime());
        notifyListeners(*_custom);
    } else {
        notifyListeners(QDateTime::currentDateTime());
    }
}

void Clock::displayTime(const QDateTime& datetime) {
    notifyListeners(datetime);
    QString text = datetime.toString("hh:mm:ss  dd-MM-yy");
    if ((datetime.time().second() % 2) == 0) {
        text[2] = ' ';
        text[5] = ' ';
    }
    display(text);
}

void Clock::subscribe(ClockListener* clockListener) {
    _clockListeners.push_back(clockListener);
}

void Clock::unsubscribe(ClockListener* clockListener) {
    _clockListeners.remove(clockListener);
}

void Clock::notifyListeners(const QDateTime& newTime) {
    for (ClockListener* clockListener : _clockListeners) {
        clockListener->onTimeChanged(newTime);
    }
}
