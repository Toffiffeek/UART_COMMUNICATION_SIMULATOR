/**/
#include<iostream>


#include "UARTConfig.hpp"
#include "ConsoleUI.hpp"
#include "Enums.hpp"

int main(){
    ConsoleUI menu;
    UARTConfig config;
    menu.displayMenu();
    menu.displayBaudRateMenu();
    int choice = menu.getIntInput(1, 5);
    BaudRate rate = menu.convertChoiceToBoudRate(choice);
    config.setBaudRate(rate);
    std::cout << static_cast<int>(config.getBaudRate());

    return 0;
}