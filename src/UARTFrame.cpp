/*Implementation of methods declared in UARTFrame.hpp*/

#include "UARTFrame.hpp"
#include<iostream>
#include<vector>
#include<string>

    std::string get_message(){
        std::string message;
        std::getline(std::cin, message);
        return message;
    }


