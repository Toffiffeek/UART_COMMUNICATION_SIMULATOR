#include "UARTReceiver.hpp"
#include <iostream>
#include <vector>
#include <queue>

UARTReceiver::UARTReceiver(std::queue<std::vector<bool>> &transmittedBitSets, const UARTConfig &config){
    decodeQueue(transmittedBitSets, config);
}

void UARTReceiver::decodeQueue(std::queue<std::vector<bool>>& bitSets, const UARTConfig& config){
    for(std::size_t i = 0; i < bitSets.size(); i++){
        framesReceived.push(UARTFrame(bitSets.front(), config));
    }
}

const std::queue<UARTFrame> &UARTReceiver::getReceivedFrames() const{
    return framesReceived;
}