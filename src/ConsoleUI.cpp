#include "ConsoleUI.hpp"
#include<iostream>

ConsoleUI::ConsoleUI(){}

void ConsoleUI::displayMenu() const{
    std::cout << "==================================\n";
    std::cout << "     UART CONFIGURATION MENU      \n";
    std::cout << "==================================\n";
}

void ConsoleUI::displayBaudRateMenu() const{
    std::cout << "PRESS NUMBER TO CHOOSE DESIRABLE BAUD RATE\n";
    std::cout << "1. 9600 bps\n";
    std::cout << "2. 19200 bps\n";
    std::cout << "3. 38400 bps\n";
    std::cout << "4. 57600 bps\n";
    std::cout << "5. 115200 bps\n";
}

int ConsoleUI::getIntInput(int min, int max) const{
    while(true){
        int number;
        std::cout << "Enter number: ";
        std::cin >> number;
        if(std::cin.fail() || number > max || number < min){
            std::cout << "Invalid number\n";
            std::cin.clear(); 
            std::cin.ignore(1000, '\n');
            continue;
        }
        return number;
    }
}

BaudRate ConsoleUI::convertChoiceToBoudRate(int choice) const{
        switch(choice){
        case 1: 
            return BaudRate::BR_9600;
        case 2: 
            return BaudRate::BR_19200;
        case 3:
            return BaudRate::BR_38400;
        case 4: 
            return BaudRate::BR_57600;
        case 5: 
            return BaudRate::BR_115200;
        default:
            throw std::invalid_argument("Invalid choice");
    }
}