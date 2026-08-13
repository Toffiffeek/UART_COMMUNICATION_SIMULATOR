/**/
#pragma once

#include "UARTConfig.hpp"
#include <iostream>
#include <vector>

class UARTFrame
{
private:
    static constexpr int DATA_BITS = 8;
    char character;
    std::vector<bool> bits;

    void characterToBits(char character, std::vector<bool> &frame);
    void addStartBit(std::vector<bool> &frame);
    void addStopBits(std::vector<bool> &frame, const UARTConfig &config);
    void addParityBit(std::vector<bool> &frame, const UARTConfig &config, bool evenNumberOfOnes);
    void buildFrame(char character, std::vector<bool> &frame, const UARTConfig &config);
    bool calculateParityBit(const std::vector<bool> &dataBits) const;
    void stripConfigBits(std::vector<bool> &frame, const UARTConfig &config);
    void bitsToCharacter(std::vector<bool> &frame);
    int validateFrame(const std::vector<bool> &frame) const;
public:
    UARTFrame(std::vector<bool> &bits, const UARTConfig &config);
    UARTFrame(char character, const UARTConfig &config);
    char getCharacter() const;
    const std::vector<bool> &getBits() const;    
};