#include "UARTChannel.hpp"
#include <cstdlib>
#include <vector>

UARTChannel::UARTChannel() : generator(std::random_device{}()), distribution(1, 1000)
{};

std::vector<bool> UARTChannel::errorInjection(std::vector<bool> transmittedBits){
    for(std::size_t i = 0; transmittedBits.size(); i++)
    {
        int randomNumber = distribution(generator);
        if(randomNumber == 1){
            transmittedBits[i] = !transmittedBits[i];
        }
    }
    return transmittedBits;
}

std::vector<bool> UARTChannel::transmit(UARTFrame transmittedFrame){
    errorInjection(transmittedFrame.getBits());
}