#pragma once

#include "Enums.hpp"

class ConsoleUI{
    public:
    ConsoleUI();
    void displayMenu() const;
    void displayBaudRateMenu() const;
    int getIntInput(int min, int max) const;
    BaudRate convertChoiceToBoudRate(int choice) const;
};