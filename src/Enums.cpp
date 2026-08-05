#include "Enums.hpp"
#include<iostream>
#include <stdexcept>

int baudRateToInt(BaudRate baudRate)
{
    switch (baudRate)
    {
    case BaudRate::B9600:
        return 9600;
    case BaudRate::B38400:
        return 38400;
    case BaudRate::B57600:
        return 57600;
    case BaudRate::B19200:
        return 19200;
    case BaudRate::B115200:
        return 115200;
    default:
        throw std::invalid_argument("INVALID VALUE");
    }
}

int stopBitsToInt(StopBits stopBits)
{
    switch (stopBits)
    {
    case StopBits::One:
        return 1;
    case StopBits::Two:
        return 2;
    default:
        throw std::invalid_argument("INVALID VALUE");
    }
}

std::string parityModeToString(ParityMode parity)
{
    switch (parity)
    {
    case ParityMode::Even:
        return "EVEN";
    case ParityMode::Odd:
        return "ODD";
    case ParityMode::None:
        return "NONE";
    default:
        throw std::invalid_argument("INVALID VALUE");
    }
}