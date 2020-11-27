//
// Created by Andrew on 25-Oct-20.
//

#ifndef ATM_CARDDAO_H
#define ATM_CARDDAO_H

#include <QtSql/QSqlQuery>
#include <QtCore/QObject>
#include "logics/bank_services/Card.h"

class CardDAO {
public:
	static CardDAO& getInstance();

	void saveCard(Card&) const;

	Card* getById(const QString& id) const;

	bool updateCard(const Card&) const;

	void deleteById(const QString& id) const;

private:
	static void initialize();

	Card* buildCard(const QSqlQuery&) const;

	CardDAO() = default;
};


#endif //ATM_CARDDAO_H
