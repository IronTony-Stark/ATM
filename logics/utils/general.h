//
// Created by Andrew on 02-Oct-20.
//

#ifndef ATM_GENERAL_H
#define ATM_GENERAL_H

#include <QtCore/QDate>

QDate addDates(const QDate&, const QDate&);

QDate subtractDates(const QDate&, const QDate&);

QString generatePin();

template<typename T>
int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}

#endif //ATM_GENERAL_H
