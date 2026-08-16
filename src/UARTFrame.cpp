/*Implementation of methods declared in UARTFrame.hpp*/

#include "UARTFrame.hpp"
#include <iostream>
#include <vector>
#include <bitset>
#include <stdexcept>

UARTFrame::UARTFrame(std::vector<bool> &bits, const UARTConfig &config) : bits(bits)
{
    stripConfigBits(bits, config);
    bitsToCharacter(bits);
}

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
    std::bitset<DATA_BITS> bs(character);
    for (int i = 0; i < DATA_BITS; i++)
    {
        frame.push_back(bs[i]);
    }
}

void UARTFrame::bitsToCharacter(std::vector<bool> &frame)
{
    std::bitset<DATA_BITS> bs;
    for (std::size_t i = 0; i < DATA_BITS; i++)
    {
        bs[i] = frame[i + 1];
    }
    character = static_cast<char>(bs.to_ulong());
}

bool UARTFrame::calculateParityBit(const std::vector<bool> &dataBits) const
{
    int numberOfOnes = 0;
    for (bool bit : dataBits)
    {
        if (bit)
        {
            numberOfOnes++;
        }
    }
    return numberOfOnes % 2 == 0;
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

void UARTFrame::stripConfigBits(std::vector<bool> &frame, const UARTConfig &config)
{
    switch (config.getStopBits())
    {
    case StopBits::One:
        if (config.getParity() == ParityMode::None)
        {
            frame.pop_back();
        }
        else
        {
            for (int i = 0; i < 2; i++)
            {
                frame.pop_back();
            }
        }
        break;
    case StopBits::Two:
        if (config.getParity() == ParityMode::None)
        {
            frame.pop_back();
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                frame.pop_back();
            }
        }
        break;
    default:
        throw std::invalid_argument("INVALID ARGUMENT");
    }
}

int UARTFrame::checkParityError(const std::vector<bool> &frame, const UARTConfig &config) const
{
    std::vector<bool> frameToCheck = {frame.begin() + 1, frame.begin() + 10};
    bool isEven = calculateParityBit(frameToCheck);
    switch (config.getParity())
    {
    case ParityMode::Even:
        return static_cast<int>(!isEven);
    case ParityMode::Odd:
        return static_cast<int>(isEven);
    default:
        return 0;
    }
}

int UARTFrame::checkFrameError(
    const std::vector<bool> &frame,
    const UARTConfig &config) const
{
    if (frame[0] != 0)
    {
        return 1;
    }

    std::size_t stopBitIndex = 9;

    if (config.getParity() != ParityMode::None)
    {
        stopBitIndex++;
    }

    if (frame[stopBitIndex] != 1)
    {
        return 1;
    }

    if (config.getStopBits() == StopBits::Two &&
        frame[stopBitIndex + 1] != 1)
    {
        return 1;
    }

    return 0;
}