/**/
#pragma once

#include "UARTFrame.hpp"
#include "UARTConfig.hpp"
#include<iostream>
#include<queue>

class UARTReceiver{
private:
    std::queue<UARTFrame> framesReceived;
    void buildQueue(std::string message, const UARTConfig &config);

public:
    UARTReceiver(std::string message, const UARTConfig &config);
    const std::queue<UARTFrame> &getFramesToTransmit() const;
};