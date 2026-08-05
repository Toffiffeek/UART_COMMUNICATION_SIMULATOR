/**/
#pragma once

#include "UARTConfig.hpp"
#include <iostream>
#include <vector>

class UARTFrame
{
private:
    char character;
    std::vector<bool> bits;

    std::vector<bool> characterToBits(char& character, std::vector<bool>& frame);
    

    void addStartBit(std::vector<bool>& frame);
    void addStopBits(std::vector<bool>& frame, const UARTConfig& config);
    void addParityBit(std::vector<bool>& frame, const UARTConfig& config);

    std::vector<bool> buildFrame(const UARTConfig& config);

public:
    UARTFrame(char character, const UARTConfig& config);
    bool calculateParityBit(const std::vector<bool>& bits);
    char getCharacter() const;
    const std::vector<bool>& getBits() const;
};