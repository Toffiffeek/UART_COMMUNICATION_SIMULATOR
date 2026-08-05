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
    std::vector<bool> characterToBits(char character);
    bool calculateParity(std::vector<bool> frame);
    void addStartBit();
    void addStopBits();
    void addParityBits();
    std::vector<bool> buildFrame();

public:
    UARTFrame(char character, const UARTConfig& config);
    char getCharacter() const;
    std::vector<bool> getBits() const;
};