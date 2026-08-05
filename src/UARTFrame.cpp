/*Implementation of methods declared in UARTFrame.hpp*/

#include "UARTFrame.hpp"
#include <iostream>
#include <vector>
#include <bitset>

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
bool UARTFrame::calculateParityBit(const std::vector<bool>& bits){}
void UARTFrame::addStartBit(std::vector<bool>& frame){}
void UARTFrame::addStopBits(std::vector<bool>& frame, const UARTConfig& config){}
void UARTFrame::addParityBit(std::vector<bool>& frame, const UARTConfig& config){}
std::vector<bool> UARTFrame::buildFrame(const UARTConfig& config){}
