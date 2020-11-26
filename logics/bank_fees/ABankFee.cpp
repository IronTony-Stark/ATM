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

