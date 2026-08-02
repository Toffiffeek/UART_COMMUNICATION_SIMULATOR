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