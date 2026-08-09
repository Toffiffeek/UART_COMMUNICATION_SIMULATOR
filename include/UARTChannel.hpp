#pragma once
#include "UARTFrame.hpp"

class UARTChannel{
private:
    UARTFrame currentFrame;
    void errorInjection();
public:
    UARTChannel(UARTFrame currentFrame);
    

};