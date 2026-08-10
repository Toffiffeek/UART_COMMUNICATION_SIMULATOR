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
#include<bitset>

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
    std::queue<std::vector<bool>> q = channel.transmit(tx.getFramesToTransmit());
    std::queue<UARTFrame> q2 = tx.getFramesToTransmit();
    std::queue<UARTFrame> q3 = rx.getReceivedFrames();
    for(char c: message){
        ui.displayFrame(q2.front());
        ui.displayFrame(q3.front());
        std::cout << static_cast<int>(q3.front().getCharacter());
        ui.displayBits(q.front());
        q.pop();
        q2.pop();
        q3.pop();
    }
    std::cout << "test1";
    std::bitset<8> bs = 256;
    std::cout << static_cast<char>(bs.to_ulong());

    return 0;
}