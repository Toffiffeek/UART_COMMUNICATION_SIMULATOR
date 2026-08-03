/*Impementation of methods declared in UARTConfig*/
#include "UARTConfig.hpp"
#include <iostream>

UARTConfig::UARTConfig(
    BaudRate baudRate,
    StopBits stopBits,
    ParityMode parity)
    : baudRate(baudRate),
      stopBits(stopBits),
      parity(parity)
{
}

BaudRate UARTConfig::getBaudRate() const
{
    return baudRate;
}

void UARTConfig::setBaudRate(BaudRate baudRate)
{
    this->baudRate = baudRate;
}

StopBits UARTConfig::getStopBits() const
{
    return stopBits;
}

void UARTConfig::setStopBits(StopBits stopBits)
{
    this->stopBits = stopBits;
}

ParityMode UARTConfig::getParity() const
{
    return parity;
}

void UARTConfig::setParity(ParityMode parity)
{
    this->parity = parity;
}