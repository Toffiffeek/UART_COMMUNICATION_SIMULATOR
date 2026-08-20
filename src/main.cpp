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
#include <bitset>

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
    std::queue<std::vector<bool>> transmittedBits = channel.transmit(tx.getFramesToTransmit());
    ui.displayTransmision(transmittedBits, config);
    UARTReceiver rx(transmittedBits, config);
    ui.displaySummary(rx.getReceivedFrames(), rx.getDetectedParityErrors(), rx.getDetectedFrameErrors());

    return 0;
}