#include "UARTChannel.hpp"
#include <vector>
#include <queue>
#include <random>

UARTChannel::UARTChannel() : generator(std::random_device{}()), distribution(1, 1000) {};

std::vector<bool> UARTChannel::errorInjection(std::vector<bool> bits)
{
    for (std::size_t i = 0; i < bits.size(); i++)
    {
        int randomNumber = distribution(generator);
        if (randomNumber <= 5)
        {
            bits[i] = !bits[i];
        }
    }
    return bits;
}

std::queue<std::vector<bool>> UARTChannel::transmit(std::queue<UARTFrame> transmittedFrames)
{
    std::queue<std::vector<bool>> transmittedBitSets;
    while (!transmittedFrames.empty())
    {
        transmittedBitSets.push(errorInjection(transmittedFrames.front().getBits()));
        transmittedFrames.pop();
    }
    return transmittedBitSets;
}