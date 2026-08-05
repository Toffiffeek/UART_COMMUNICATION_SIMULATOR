/*Implementation of methods declared in UARTFrame.hpp*/

#include "UARTFrame.hpp"
#include <iostream>
#include <vector>
#include <bitset>

UARTFrame::UARTFrame(char character, const UARTConfig& config):character(character){
    //bits = buildFrame();
}

char UARTFrame::getCharacter() const{}
const std::vector<bool>& UARTFrame::getBits() const{}
std::vector<bool> UARTFrame::characterToBits(char character){}
bool UARTFrame::calculateParityBit(const std::vector<bool>& bits){}
void UARTFrame::addStartBit(std::vector<bool>& frame){}
void UARTFrame::addStopBits(std::vector<bool>& frame, const UARTConfig& config){}
void UARTFrame::addParityBit(std::vector<bool>& frame, const UARTConfig& config){}
std::vector<bool> UARTFrame::buildFrame(const UARTConfig& config){}
