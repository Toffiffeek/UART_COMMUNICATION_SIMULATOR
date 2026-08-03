/*Impementation of methods declared in UARTConfig*/
#include "UARTConfig.hpp"
#include<iostream>

UARTConfig::UARTConfig():baudRate(BaudRate::BR_9600), stopBits(StopBits::ONE), parity(ParityMode::NONE){} 

BaudRate UARTConfig::getBaudRate() const{
    return baudRate;
}

void UARTConfig::setBaudRate(BaudRate rate){
    baudRate = rate;
}

StopBits UARTConfig::getStopBits() const{
    return stopBits;
}

void UARTConfig::setStopBits(StopBits numberOfStopBits){
    stopBits = numberOfStopBits;
}

ParityMode UARTConfig::getParity() const{
    return parity;
}

void UARTConfig::setParity(ParityMode mode){
    parity = mode;
}