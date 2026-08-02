/**/
#pragma once

#include "Enums.hpp"


class UARTConfig{
private:
    BaudRate baudRate;
    StopBits stopBits;
    ParityMode parity;
public:
    UARTConfig();
    BaudRate getBaudRate() const;
    StopBits getStopBits() const;
    ParityMode getParity() const;
    void setBaudRate(BaudRate rate);
    void setStopBits(StopBits numberOfStopBits);
    void setParity(ParityMode mode);
};