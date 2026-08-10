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
    void decodeQueue(std::vector<bool>& bits, const UARTConfig &config);

public:
    UARTReceiver(std::vector<bool> bits, const UARTConfig &config);
    const std::queue<UARTFrame> &getReceivedFrames() const;
};