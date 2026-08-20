#include "UARTChannel.hpp"
#include <vector>
#include <queue>
#include <random>

UARTChannel::UARTChannel(const std::queue<UARTFrame> &frames) : generator(std::random_device{}()), distribution(1, 1000) {
    transmit(frames);
};

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

void UARTChannel::transmit(std::queue<UARTFrame> transmittedFrames)
{
    while (!transmittedFrames.empty())
    {
        transmittedBits.push(errorInjection(transmittedFrames.front().getBits()));
        transmittedFrames.pop();
    }
}

const std::queue<std::vector<bool>> &UARTChannel::getTransmittedBits() const{
    return transmittedBits;
}