/*Impementation of methods declared in UARTConfig*/

#include<UARTConfig.hpp>
#include<iostream>

int UARTConfig::askForBoudRate(){
    while(true){
        int choice = 0;
        std::cout << "CHOOSE DESIRABLE BOUND RATE: " << std::endl;
        std::cout << "Press \"1\"" << std::endl;
        std::cout << "Press \"2\"" << std::endl;
        std::cout << "Press \"3\"" << std::endl;
        std::cout << "Press \"4\"" << std::endl;
        std::cout << "Press \"5\"" << std::endl;
        std::cout << "Press \"6\"" << std::endl;
        std::cin >> choice;
        if(choice >= 1 && choice <= 6){
            return choice;
        }
    }
}

//Function enabling user to choose one of the available Baund Rates
void UARTConfig::setBaudRate(int choice, BAUD_RATE baudRate){
}