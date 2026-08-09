#include "UARTChannel.hpp"

UARTChannel::UARTChannel(UARTFrame currentFrame):currentFrame(currentFrame){};

void UARTChannel::errorInjection(){
    for(bool bit : currentFrame.getBits())
    {
        
    }
}