//
// Created by Andrew on 02-Oct-20.
//

#include <QtCore/QRandomGenerator>
#include "general.h"
#include "stdexcept"

QDate addDates(const QDate& d1, const QDate& d2) {
	return d1.addDays(d2.day()).addMonths(d2.month()).addYears(d2.year());
}

QDate subtractDates(const QDate& d1, const QDate& d2) {
	qint64 diff = d1.toJulianDay() - d2.toJulianDay();
	return QDate().addDays(diff);
}

QString generatePin() {
	static QRandomGenerator random;
	uint nextPin = random.bounded(10000);
	QString res = QString::number(nextPin);
	while (res.length() < 4) res.prepend('0');
	return res;
}