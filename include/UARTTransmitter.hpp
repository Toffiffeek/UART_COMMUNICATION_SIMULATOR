/**/
#pragma once

#include "UARTFrame.hpp"
#include "UARTConfig.hpp"
#include<iostream>
#include<vector>
#include<queue>

class UARTTransmitter{
private:
    std::queue<UARTFrame> framesToTransmit;
    void buildQueue(std::string message, const UARTConfig &config);

public:
    UARTTransmitter(std::string message, const UARTConfig &config);
    const std::queue<UARTFrame> &getFramesToTransmit() const;
};