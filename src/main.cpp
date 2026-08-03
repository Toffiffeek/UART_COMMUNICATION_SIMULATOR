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
    int choice;

    ui.displayMenu();

    ui.displayBaudRateMenu();
    choice = ui.getIntInput(1, 5);
    BaudRate rate = ui.convertChoiceToBaudRate(choice);
    config.setBaudRate(rate);

    ui.displayParityMenu();
    choice = ui.getIntInput(1, 3);
    ParityMode parity = ui.convertChoiceToParity(choice);
    config.setParity(parity);

    ui.displayStopBitsMenu();
    choice = ui.getIntInput(1, 2);
    StopBits stopBits = ui.convertChoiceToStopBits(choice);
    config.setStopBits(stopBits);

    return 0;
}