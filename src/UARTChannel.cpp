#include "UARTChannel.hpp"
#include <cstdlib>
#include <vector>
#include <queue>

UARTChannel::UARTChannel() : generator(std::random_device{}()), distribution(1, 1000)
{};

std::vector<bool> UARTChannel::errorInjection(std::vector<bool> bits){
    for(std::size_t i = 0; bits.size(); i++)
    {
        int randomNumber = distribution(generator);
        if(randomNumber == 1){
            bits[i] = !bits[i];
        }
    }
    return bits;
}

std::queue<std::vector<bool>> UARTChannel::transmit(std::queue<UARTFrame> transmittedFrames){
    std::queue<std::vector<bool>> transmittedBitSets;
    for(std::size_t i = 0; i < transmittedFrames.size(); i++){
        transmittedBitSets.push(errorInjection(transmittedFrames.front().getBits()));
    }
    return transmittedBitSets;
}