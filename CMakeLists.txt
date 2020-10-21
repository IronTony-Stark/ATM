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
        views/main/MainWindow.cpp
        views/main/MainWindow.h
        views/main/mainwindow.ui
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
        logics/exceptions/NoSuchCustomerPossessionException.h
        views/start/StartWindow.h
        views/start/StartWindow.cpp
        views/start/startwindow.ui
        views/registration/RegistrationWindow.h
        views/registration/RegistrationWindow.cpp
        views/registration/registrationwindow.ui
        views/mainMenu/MainMenuWindow.h
        views/mainMenu/MainMenuWindow.cpp
        views/mainMenu/mainmenuwindow.ui
        views/transaction/TransactionWindow.h
        views/transaction/TransactionWindow.cpp
        views/transaction/transactionwindow.ui
        views/payment/PaymentWindow.h
        views/payment/PaymentWindow.cpp
        views/payment/paymentwindow.ui
        views/deposit/DepositWindow.h
        views/deposit/DepositWindow.cpp
        views/deposit/depositwindow.ui
        views/credit/CreditWindow.h
        views/credit/CreditWindow.cpp
        views/credit/creditwindow.ui
        )

target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)