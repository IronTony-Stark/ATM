cmake_minimum_required(VERSION 3.17)
project(ATM)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH $ENV{QtPath}) # e.g. C:/Qt/5.15.1/mingw81_64/


find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(ATM
        main.cpp
        MainWindow.cpp
        MainWindow.h
        mainwindow.ui
        logics/bank_fees/ABankFee.h
        logics/bank_fees/BankFeeProvider.cpp
        logics/bank_fees/BankFeeProvider.h
        logics/bank_services/Card.cpp
        logics/bank_services/Card.h
        logics/bank_services/Credit.cpp
        logics/bank_services/Credit.h
        logics/bank_services/Deposit.cpp
        logics/bank_services/Deposit.h
        logics/Customer.cpp
        logics/Customer.h
        logics/exceptions/NotEnoughMoneyException.cpp
        logics/exceptions/NotEnoughMoneyException.h
        logics/utils/Money.cpp
        logics/utils/Money.h
        logics/utils/general.h
        logics/utils/general.cpp
        logics/exceptions/NoSuchCardException.h
        logics/exceptions/NoSuchCreditException.h
        logics/exceptions/NoSuchDepositException.h
        logics/exceptions/NoSuchCustomerPossessionException.cpp
        logics/exceptions/NoSuchCustomerPossessionException.h logics/managers/CustomerDataManager.cpp logics/managers/CustomerDataManager.h logics/managers/OperationManager.cpp logics/managers/OperationManager.h logics/auth/Authorizer.cpp logics/auth/Authorizer.h logics/auth/Registrator.cpp logics/auth/Registrator.h logics/bank_fees/CreditConditions.cpp logics/bank_fees/CreditConditions.h logics/bank_fees/DepositConditions.cpp logics/bank_fees/DepositConditions.h logics/exceptions/CreditRepayOverheadException.cpp logics/exceptions/CreditRepayOverheadException.h)

target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)