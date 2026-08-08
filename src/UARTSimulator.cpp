/*Implementation of methonds declared in UARTSimulator.hpp*/

#include<UARTSimulator.hpp>
#include<iostream>

UARTSimulator::UARTSimulator(std::string message, const UARTConfig& config){
    buildQueue(message, config);
}

void UARTSimulator::buildQueue(std::string message, const UARTConfig &config){
    for(char character:message){
        frames.push(UARTFrame::UARTFrame(character, config));
    }
}