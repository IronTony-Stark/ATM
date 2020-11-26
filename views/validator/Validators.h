//
// Created by Iron Tony on 26/11/2020.
//

#ifndef MOOP_ATM_VALIDATORS_H
#define MOOP_ATM_VALIDATORS_H

constexpr const char* userNameRegex = R"(^[0-9]{12}$)";
constexpr const char* phoneRegex = R"(^\+?(\d.*){3,}$)";
constexpr const char* taxRegex = R"(^([A-Z]{2})?[0-9]{8}$)";
constexpr const char* incomeRegex = R"(^[1-9][0-9]{3,}$)";
constexpr const char* pinRegex = R"(^[0-9]{4}$)";
constexpr const char* cardNumberRegex = R"(^[1-9][0-9]{2,}$)";
constexpr const char* amountRegex = R"(^[0-9]{12}$)";
constexpr const char* objectName = ".+";

#endif //MOOP_ATM_VALIDATORS_H
