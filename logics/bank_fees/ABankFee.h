//
// Created by Andrew on 30-Sep-20.
//

#ifndef ATM_BANKFEE_H
#define ATM_BANKFEE_H

struct ABankFee {
	enum FeeType {
		STANDARD,
		UNIVERSAL,
		GOLDEN,
		PLATINUM
	};

	[[nodiscard]] double replenishFee() const { return _replenishFee; }

	[[nodiscard]] double withdrawFee() const { return _withdrawFee; }

	[[nodiscard]] double transferFee() const { return _transferFee; }

protected:
	explicit ABankFee(double replenish, double withdraw, double transfer) :
			_replenishFee(replenish), _withdrawFee(withdraw), _transferFee(transfer) {}

	const double _replenishFee;
	const double _withdrawFee;
	const double _transferFee;
};

struct StandardFee : ABankFee {
	StandardFee() : ABankFee(1, 2, 3) {}
};

struct UniversalFee : ABankFee {
	UniversalFee() : ABankFee(1, 2, 3) {}
};

struct GoldenFee : ABankFee {
	GoldenFee() : ABankFee(1, 2, 3) {}
};

struct PlatinumFee : ABankFee {
	PlatinumFee() : ABankFee(1, 2, 3) {}
};

#endif //ATM_BANKFEE_H
