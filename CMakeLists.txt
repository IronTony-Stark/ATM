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
        logics/bank_fees/ABankFee.h logics/bank_fees/BankFeeProvider.cpp logics/bank_fees/BankFeeProvider.h logics/Card.cpp logics/Card.h logics/bank_services/Credit.cpp logics/bank_services/Credit.h logics/bank_services/Deposit.cpp logics/bank_services/Deposit.h logics/Customer.cpp logics/Customer.h logics/exceptions/NotEnoughMoneyException.cpp logics/exceptions/NotEnoughMoneyException.h logics/utils/generator.cpp logics/utils/dates.cpp logics/utils/dates.h logics/utils/generator.h)

target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)