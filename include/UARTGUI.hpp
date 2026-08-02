#pragma once

#include "Enums.hpp"

class UARTGUI{
    public:
    UARTGUI();
    void displayMenu() const;
    void displayBaudRateMenu() const;
    int getIntInput(int min, int max) const;
    BaudRate convertChoiceToBoudRate(int choice);
};