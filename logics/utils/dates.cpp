//
// Created by Andrew on 30-Sep-20.
//

#include "dates.h"
#include "stdexcept"

QDate addDates(const QDate d1, const QDate d2) {
	return d1.addDays(d2.day()).addMonths(d2.month()).addYears(d2.year());
}

QDate subtractDates(const QDate& d1, const QDate& d2) {
	//todo: implement
	throw std::runtime_error("not implemented exception");
}