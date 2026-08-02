/**/
#pragma once

#include "Enums.hpp"


class UARTConfig{
private:
    BaudRate baudRate;
    int stopBits;
    bool parityEnabled;
public:
    UARTConfig();
    BaudRate getBaudRate() const;
    void setBaudRate(BaudRate rate);
};