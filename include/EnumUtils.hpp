#pragma once

#include "Enums.hpp"
#include <iostream>

int baudRateToInt(BaudRate baudrate);
int stopBitsToInt(StopBits stopBits);
std::string parityModeToString(ParityMode parity);