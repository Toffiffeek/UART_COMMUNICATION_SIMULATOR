/*Implementation of methonds declared in UARTSimulator.hpp*/

#include "UARTTransmitter.hpp"
#include <iostream>

UARTTransmitter::UARTTransmitter(std::string message, const UARTConfig &config)
{
    buildQueue(message, config);
}

void UARTTransmitter::buildQueue(std::string message, const UARTConfig &config)
{
    for (char character : message)
    {
        framesToTransmit.push(UARTFrame(character, config));
    }
}

const std::queue<UARTFrame> &UARTTransmitter::getFramesToTransmit() const
{
    return framesToTransmit;
}