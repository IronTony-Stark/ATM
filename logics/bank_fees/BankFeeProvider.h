//
// Created by Andrew on 30-Sep-20.
//

#ifndef ATM_BANKFEEPROVIDER_H
#define ATM_BANKFEEPROVIDER_H

#include <QHash>
#include "ABankFee.h"


class BankFeeProvider {
public:
	const ABankFee& getBankFee(ABankFee::CardType);

	static BankFeeProvider& getInstance();

	~BankFeeProvider();

private:
	QHash<ABankFee::CardType, ABankFee*> fees;
};


#endif //ATM_BANKFEEPROVIDER_H
