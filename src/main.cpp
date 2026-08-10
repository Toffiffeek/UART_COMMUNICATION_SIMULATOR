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
#include "UARTChannel.hpp"
#include "UARTReceiver.hpp"

int main()
{
    ConsoleUI ui;

    ui.displayMenu();

    UARTConfig config(
        ui.getBaudRateChoice(),
        ui.getStopBitsChoice(),
        ui.getParityChoice());
    ui.displayConfig(config);
    std::string message = ui.getStringInput();
    UARTTransmitter tx(message, config);
    UARTChannel channel;
    UARTReceiver rx(channel.transmit(tx.getFramesToTransmit()), config);
    std::queue<UARTFrame> q1 = rx.getReceivedFrames(); 
    for(char c: message){
        ui.displayFrame(q1.front());
        q1.pop();
    }

    return 0;
}