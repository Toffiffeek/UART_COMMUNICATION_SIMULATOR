#pragma once
#include "UARTFrame.hpp"
#include <random>
#include <vector>

class UARTChannel{
private:
    std::mt19937 generator;
    std::uniform_int_distribution<int> distribution;
    void errorInjection(std::vector<bool> transmitedFrame);
public:
    UARTChannel();
};