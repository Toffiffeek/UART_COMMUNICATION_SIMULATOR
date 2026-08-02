/*Impementation of methods declared in UARTConfig*/
#include "UARTConfig.hpp"
#include<iostream>

UARTConfig::UARTConfig():baudRate(0), stopBits(0), parityEnabled(0){} 

void UARTConfig::displayMenu() const{
    std::cout << "==================================\n";
    std::cout << "     UART CONFIGURATION MENU      \n";
    std::cout << "==================================\n";
}