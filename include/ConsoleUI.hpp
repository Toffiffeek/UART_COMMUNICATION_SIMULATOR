#pragma once

#include "Enums.hpp"
#include "UARTConfig.hpp"
#include <string>

class ConsoleUI
{
public:
    ConsoleUI();
    void displayMenu() const;
    void displayBaudRateMenu() const;
    void displayParityMenu() const;
    void displayStopBitsMenu() const;
    void displayConfig(const UARTConfig &config) const;
    BaudRate convertChoiceToBaudRate(int choice) const;
    ParityMode convertChoiceToParity(int choice) const;
    StopBits convertChoiceToStopBits(int choice) const;
    int getIntInput(int min, int max) const;
    std::string getStringInput() const;
    BaudRate getBaudRateChoice() const;
    ParityMode getParityChoice() const;
    StopBits getStopBitsChoice() const;
};