//
// Created by Andrew on 30-Sep-20.
//

#ifndef ATM_BANKFEE_H
#define ATM_BANKFEE_H

#include <logics/utils/Money.h>
#include <unordered_map>

struct ABankFee {
	enum CardType {
		STANDARD,
		UNIVERSAL,
		GOLDEN,
		PLATINUM
	};

    static const std::unordered_map<std::string, CardType> CARD_TYPES;

	[[nodiscard]] double replenishFee() const { return _replenishFee; }

	[[nodiscard]] double withdrawFee() const { return _withdrawFee; }

	[[nodiscard]] double transferFee() const { return _transferFee; }

	[[nodiscard]] Money cardPayment() const { return _cardPayment; }

protected:
	explicit ABankFee(double replenish, double withdraw, double transfer, Money cardPayment) :
			_replenishFee(replenish), _withdrawFee(withdraw), _transferFee(transfer), _cardPayment(cardPayment) {}

	const double _replenishFee;
	const double _withdrawFee;
	const double _transferFee;
	const Money _cardPayment;
};

struct StandardFee : ABankFee {
	StandardFee() : ABankFee(0.05, 0.05, 0.04, 0) {}
};

struct UniversalFee : ABankFee {
	UniversalFee() : ABankFee(0.04, 0.045, 0.03, 50) {}
};

struct GoldenFee : ABankFee {
	GoldenFee() : ABankFee(0.03, 0.035, 0.03, 65) {}
};

struct PlatinumFee : ABankFee {
	PlatinumFee() : ABankFee(0, 0.02, 0.012, 80) {}
};

#endif //ATM_BANKFEE_H
