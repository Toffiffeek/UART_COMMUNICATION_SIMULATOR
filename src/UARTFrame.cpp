/*Implementation of methods declared in UARTFrame.hpp*/

#include "UARTFrame.hpp"
#include <iostream>
#include <vector>
#include <bitset>

UARTFrame::UARTFrame(char character, const UARTConfig& config):character(character){
    bits = buildFrame();
}

char UARTFrame::getCharacter() const{
    return character;
}

std::vector<bool> UARTFrame::getBits() const{
    return bits;
}

std::vector<bool> UARTFrame::characterToBits(char character){
    std::vector<bool> frame;
    std::bitset<8> binary(character);
    //copying from least significant bit to most siginificant bit
    for(int i = 0; i < 7; i++){
        frame.push_back(binary[i]);
    }
}