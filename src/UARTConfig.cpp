/*Impementation of methods declared in UARTConfig*/
#include "UARTConfig.hpp"
#include<iostream>

UARTConfig::UARTConfig():baudRate(BaudRate::BR_9600), stopBits(0), parityEnabled(0){} 

BaudRate UARTConfig::getBaudRate() const{
    return baudRate;
}

void UARTConfig::setBaudRate(BaudRate rate){
    baudRate = rate;
}