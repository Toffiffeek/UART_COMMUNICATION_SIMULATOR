/**/
#pragma once

#include "UARTFrame.hpp"
#include "UARTConfig.hpp"
#include<iostream>
#include<vector>
#include<queue>

class UARTSimulator{
private:
    std::queue<UARTFrame> frames;
public:
    UARTSimulator::UARTSimulator(std::string message, const UARTConfig &config);


    void buildQueue(std::string message, const UARTConfig &config);
};