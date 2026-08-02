cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME UART_COMMUNICATION_SIMULATOR)

project(
    ${PROJECT_NAME}
    VERSION 1.0
    LANGUAGES CXX
)

add_executable(
    ${PROJECT_NAME}
    src/main.cpp
    src/UARTConfig.cpp
    src/UARTFrame.cpp
    src/UARTsimulator.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
        include
)