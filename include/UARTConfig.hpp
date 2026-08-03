/**/
#pragma once

#include "Enums.hpp"

class UARTConfig
{
private:
    BaudRate baudRate;
    StopBits stopBits;
    ParityMode parity;

public:
    UARTConfig(
        BaudRate baudRate,
        StopBits stopBits,
        ParityMode parity);

    BaudRate getBaudRate() const;
    StopBits getStopBits() const;
    ParityMode getParity() const;
    void setBaudRate(BaudRate baudRate);
    void setStopBits(StopBits stopBits);
    void setParity(ParityMode parity);
};