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
#include "UARTTransmitter.hpp"

int main()
{
    ConsoleUI ui;

    ui.displayMenu();

    UARTConfig config(
        ui.getBaudRateChoice(),
        ui.getStopBitsChoice(),
        ui.getParityChoice());

    ui.displayConfig(config);

    std::string str = ui.getStringInput();
    UARTTransmitter tx(str, config);
    std::queue<UARTFrame> f = tx.getFramesToTransmit();
    for(char character: str){
        ui.displayFrame(f.front());
        f.pop();
    }
    std::vector<bool> bits = {
    0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1};
    UARTFrame f2(bits, config);
    ui.displayFrame(f2);
    return 0;
}