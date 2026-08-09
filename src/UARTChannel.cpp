#include "UARTChannel.hpp"
#include <cstdlib>
#include <vector>

UARTChannel::UARTChannel():generator(std::random_device{}()), distribution(1, 1000){};

void UARTChannel::errorInjection(std::vector<bool> transmittedFrame){
    for(std::size_t i = 0; transmittedFrame.size(); i++)
    {
        int randomNumber = distribution(generator);
        if(randomNumber == 1){
            transmittedFrame[i] = !transmittedFrame[i];
        }
    }
}