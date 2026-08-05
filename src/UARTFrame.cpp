/*Implementation of methods declared in UARTFrame.hpp*/

#include "UARTFrame.hpp"
#include <iostream>
#include <vector>
#include <bitset>
#include <stdexcept>

UARTFrame::UARTFrame(char character, const UARTConfig& config):character(character){
    bits = characterToBits(character, bits);
}

char UARTFrame::getCharacter() const{
    return character;
}
const std::vector<bool>& UARTFrame::getBits() const{
    return bits;
}
std::vector<bool> UARTFrame::characterToBits(char& character, std::vector<bool>& frame){
    std::bitset<8> bs(character);
    for(int i = 0; i < 8; i++){
        frame.push_back(bs[i]);
    }
    return frame;
}
bool UARTFrame::calculateParityBit(const std::vector<bool>& dataBits){
    int numberOfOnes = 0;
    for(int i = 0; i < 8; i++){
        if(dataBits[i]){
            numberOfOnes++;
        }
    }
    return (numberOfOnes % 2 == 0) ? 1 : 0;
}
std::vector<bool> UARTFrame::addStartBit(std::vector<bool>& frame){
    frame.push_back(0);
    return frame;
}
std::vector<bool> UARTFrame::addStopBits(std::vector<bool>& frame, const UARTConfig& config){
    switch(config.getStopBits()){
        case StopBits::One:
            frame.push_back(1);
            return frame;
        case StopBits::Two:
            for(int i = 0; i < 2; i++){
                frame.push_back(1);
            }
            return frame;
        default:
            throw std::invalid_argument("INVALID VALUE");
    }
}
std::vector<bool> UARTFrame::addParityBit(std::vector<bool>& frame, const UARTConfig& config){}
std::vector<bool> UARTFrame::buildFrame(std::vector<bool>& frame, const UARTConfig& config){}
