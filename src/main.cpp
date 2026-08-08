/**
 * @file main.cpp
 * @brief Main entry point for the UART Communication Simulator.
 *
 * Handles the initialization of the user interface and
 * configuration of UART communication parameters.
 */
#include <iostream>
#include <vector>

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
    char c;
    std::cout << "message: ";
    std::cin >> c;

    UARTFrame frame(c, config);
    ui.displayFrame(frame);

}