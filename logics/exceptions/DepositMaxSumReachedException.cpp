//
// Created by Vladyslav Synytsyn on 23/10/2020.
//

#include "DepositMaxSumReachedException.h"

const char* DepositMaxSumReachedException::what() const noexcept {
	return _message.c_str();
}
