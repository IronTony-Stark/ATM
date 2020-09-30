//
// Created by Andrew on 30-Sep-20.
//

#include "BankFeeProvider.h"


const ABankFee& BankFeeProvider::getBankFee(ABankFee::FeeType feeType) {
	if (!fees.contains(feeType))
		switch (feeType) {
			case ABankFee::STANDARD:
				fees[feeType] = new StandardFee();
				break;
			case ABankFee::UNIVERSAL:
				fees[feeType] = new UniversalFee();
				break;
			case ABankFee::GOLDEN:
				fees[feeType] = new GoldenFee();
				break;
			case ABankFee::PLATINUM:
				fees[feeType] = new PlatinumFee();
				break;
		}
	return *fees.value(feeType);
}

BankFeeProvider& BankFeeProvider::getInstance() {
	static BankFeeProvider feeProvider;
	return feeProvider;
}

BankFeeProvider::~BankFeeProvider() {
	auto iter = fees.begin();
	while (iter != fees.end()) {
		delete iter.value();
	}
}
