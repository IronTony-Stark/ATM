//
// Created by Iron Tony on 26/11/2020.
//

#include "ABankFee.h"

const std::unordered_map<std::string, ABankFee::CardType> ABankFee::CARD_TYPES = {
        {"STANDARD",  ABankFee::STANDARD},
        {"UNIVERSAL", ABankFee::UNIVERSAL},
        {"GOLDEN",    ABankFee::GOLDEN},
        {"PLATINUM",  ABankFee::PLATINUM}
};

bool ABankFee::operator==(const ABankFee& rhs) const {
	return _replenishFee == rhs._replenishFee &&
		   _withdrawFee == rhs._withdrawFee &&
		   _transferFee == rhs._transferFee &&
		   _cardPayment == rhs._cardPayment;
}

bool ABankFee::operator!=(const ABankFee& rhs) const {
	return !(rhs == *this);
}