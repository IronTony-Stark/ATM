//
// Created by Vladyslav Synytsyn on 23/10/2020.
//

#include "CustomerRegistrationException.h"

std::ostream& operator<<(std::ostream& os, CustomerRegistrationException& ex) {
    os << "Error while registration: " << ex.what() << std::endl;
    return os;
}

const char* CustomerRegistrationException::what() const noexcept {
	return _message.c_str();
}
