/**/
#pragma once

#include "UARTFrame.hpp"
#include "UARTConfig.hpp"
#include<iostream>
#include<queue>
#include<vector>

class UARTReceiver{
private:
    std::queue<UARTFrame> framesReceived;
    void decodeQueue(std::queue<std::vector<bool>> bitSets, const UARTConfig &config);

public:
    UARTReceiver(std::queue<std::vector<bool>> transmittedBitSets, const UARTConfig &config);
    const std::queue<UARTFrame> &getReceivedFrames() const;
};