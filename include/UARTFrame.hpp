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
    

    std::vector<bool> addStartBit(std::vector<bool>& frame);
    std::vector<bool> addStopBits(std::vector<bool>& frame, const UARTConfig& config);
    std::vector<bool> addParityBit(std::vector<bool>& frame, const UARTConfig& config);

    std::vector<bool> buildFrame(std::vector<bool>& frame, const UARTConfig& config);

public:
    UARTFrame(char character, const UARTConfig& config);
    bool calculateParityBit(const std::vector<bool>& dataBits);
    char getCharacter() const;
    const std::vector<bool>& getBits() const;
};