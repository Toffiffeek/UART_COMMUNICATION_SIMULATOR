#pragma once

#include "Enums.hpp"
#include "UARTConfig.hpp"
#include "UARTFrame.hpp"
#include "UARTTransmitter.hpp"
#include <string>
#include <vector>
#include <queue>

class ConsoleUI
{
public:
    ConsoleUI();

    void displayMenu() const;
    int getIntInput(int min, int max) const;
    std::string getStringInput() const;
    
    void displayBaudRateMenu() const;
    void displayParityMenu() const;
    void displayStopBitsMenu() const;

    BaudRate convertChoiceToBaudRate(int choice) const;
    ParityMode convertChoiceToParity(int choice) const;
    StopBits convertChoiceToStopBits(int choice) const;

    BaudRate getBaudRateChoice() const;
    ParityMode getParityChoice() const;
    StopBits getStopBitsChoice() const;

    void displayConfig(const UARTConfig &config) const;

    void displayBits(const std::vector<bool> &bits) const;
    void displayFrame(const UARTFrame &frame) const;
    void displayTransmision(const std::vector<bool> &bits) const;
    void displayMessage(std::queue<UARTFrame> frames) const;
};