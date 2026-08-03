#pragma once

#include "Enums.hpp"
#include<string>

class ConsoleUI{
    public:
    ConsoleUI();
    void displayMenu() const;
    void displayBaudRateMenu() const;
    void displayParityMenu() const;
    void displayStopBitsMenu() const;
    void displayCurrentConfiguration() const;
    BaudRate convertChoiceToBaudRate(int choice) const;
    ParityMode convertChoiceToParity(int choice) const;
    StopBits convertChoiceToStopBits(int choice) const;
    int getIntInput(int min, int max) const;
    std::string getStringInput() const;

    BaudRate getBaudRateChoice() const;
    ParityMode getParityChoice() const;
    StopBits getStopBitsChoice() const;
};