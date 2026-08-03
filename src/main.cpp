/**
 * @file main.cpp
 * @brief Main entry point for the UART Communication Simulator.
 *
 * Handles the initialization of the user interface and
 * configuration of UART communication parameters.
 */
#include<iostream>


#include "UARTConfig.hpp"
#include "ConsoleUI.hpp"
#include "Enums.hpp"

int main(){
    ConsoleUI ui;
    UARTConfig config;

    ui.displayMenu();
    BaudRate rate = ui.getBaudRateChoice();
    config.setBaudRate(rate);

    ParityMode parity = ui.getParityChoice();
    config.setParity(parity);

    StopBits stopBits = ui.getStopBitsChoice();
    config.setStopBits(stopBits);

    return 0;
}