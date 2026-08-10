#include "UARTReceiver.hpp"
#include <iostream>
#include <vector>
#include <queue>

UARTReceiver::UARTReceiver(std::queue<std::vector<bool>> transmittedBitSets, const UARTConfig &config){
    decodeQueue(transmittedBitSets, config);
}

void UARTReceiver::decodeQueue(std::queue<std::vector<bool>> bitSets, const UARTConfig& config){
    while(!bitSets.empty()){
        framesReceived.push(UARTFrame(bitSets.front(), config));
        framesReceived.pop();
    }
}

const std::queue<UARTFrame> &UARTReceiver::getReceivedFrames() const{
    return framesReceived;
}