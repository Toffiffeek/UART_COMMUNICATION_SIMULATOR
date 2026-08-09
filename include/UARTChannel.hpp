#pragma once
#include "UARTFrame.hpp"
#include <random>
#include <vector>

class UARTChannel{
private:
    std::mt19937 generator;
    std::uniform_int_distribution<int> distribution;
    std::vector<bool> errorInjection(std::vector<bool> transmittedBits);
    std::vector<bool> transmit(UARTFrame transmittedFrame);
public:
    UARTChannel();
};