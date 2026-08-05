/**
 * @file main.cpp
 * @brief Main entry point for the UART Communication Simulator.
 *
 * Handles the initialization of the user interface and
 * configuration of UART communication parameters.
 */
#include <iostream>
#include<vector>

#include "UARTConfig.hpp"
#include "ConsoleUI.hpp"
#include "Enums.hpp"
#include "UARTFrame.hpp"

int main()
{
    ConsoleUI ui;

    ui.displayMenu();

    UARTConfig config(
        ui.getBaudRateChoice(),
        ui.getStopBitsChoice(),
        ui.getParityChoice());

    ui.displayConfig(config);

    UARTFrame frame('c', config);
    std::cout << frame.getCharacter();
    std::vector<bool> test = frame.getBits();
    for(int i = 0; i < 8; i++){
        std::cout << test[i];
    }

    return 0;
}