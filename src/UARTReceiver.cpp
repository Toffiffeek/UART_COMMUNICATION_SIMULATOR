#include "UARTReceiver.hpp"
#include <iostream>
#include <vector>
#include <queue>

UARTReceiver::UARTReceiver(std::vector<bool> bits, const UARTConfig &config){
    decodeQueue(bits, config);
}

void UARTReceiver::decodeQueue(std::vector<bool>& bits, const UARTConfig& config){
    framesReceived.push(UARTFrame(bits, config));
}

const std::queue<UARTFrame> &UARTReceiver::getReceivedFrames() const{
    return framesReceived;
}