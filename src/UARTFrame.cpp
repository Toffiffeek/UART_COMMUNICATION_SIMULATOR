/*Implementation of methods declared in UARTFrame.hpp*/

#include "UARTFrame.hpp"
#include <iostream>
#include <vector>
#include <bitset>
#include <stdexcept>

UARTFrame::UARTFrame(char character, const UARTConfig &config) : character(character)
{
    buildFrame(character, bits, config);
}

char UARTFrame::getCharacter() const
{
    return character;
}

const std::vector<bool> &UARTFrame::getBits() const
{
    return bits;
}

void UARTFrame::characterToBits(char character, std::vector<bool> &frame)
{
    std::bitset<8> bs(character);
    for (int i = 0; i < 8; i++)
    {
        frame.push_back(bs[i]);
    }
}

bool UARTFrame::calculateParityBit(const std::vector<bool> &dataBits) const
{
    int numberOfOnes = 0;
    // Iterating from 1 to avoid start bit
    for (int i = 1; i < 9; i++)
    {
        if (dataBits[i])
        {
            numberOfOnes++;
        }
    }
    return (numberOfOnes % 2 == 0) ? 1 : 0;
}

void UARTFrame::addStartBit(std::vector<bool> &frame)
{
    frame.push_back(0);
}

void UARTFrame::addStopBits(std::vector<bool> &frame, const UARTConfig &config)
{
    switch (config.getStopBits())
    {
    case StopBits::One:
        frame.push_back(1);
        break;
    case StopBits::Two:
        for (int i = 0; i < 2; i++)
        {
            frame.push_back(1);
        }
        break;
    default:
        throw std::invalid_argument("INVALID VALUE");
    }
}

void UARTFrame::addParityBit(std::vector<bool> &frame, const UARTConfig &config, bool evenNumberOfOnes)
{
    switch (config.getParity())
    {
    case ParityMode::None:
        break;
    case ParityMode::Even:
        evenNumberOfOnes ? frame.push_back(0) : frame.push_back(1);
        break;
    case ParityMode::Odd:
        evenNumberOfOnes ? frame.push_back(1) : frame.push_back(0);
        break;
    default:
        throw std::invalid_argument("INVALID VALUE");
    }
}

void UARTFrame::buildFrame(char character, std::vector<bool> &frame, const UARTConfig &config)
{
    frame.clear();
    addStartBit(frame);
    characterToBits(character, frame);
    addParityBit(frame, config, calculateParityBit(frame));
    addStopBits(frame, config);
}
