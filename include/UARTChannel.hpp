#pragma once
#include "UARTFrame.hpp"
#include <random>
#include <vector>
#include <queue>

class UARTChannel{
private:
    std::mt19937 generator;
    std::uniform_int_distribution<int> distribution;

    std::vector<bool> errorInjection(std::vector<bool> transmittedBits);
    std::vector<bool> transmit(const std::queue<UARTFrame> frames);
public:
    UARTChannel();
};