#include "UARTReceiver.hpp"
#include <iostream>
#include <vector>
#include <queue>

UARTReceiver::UARTReceiver(std::queue<std::vector<bool>> transmittedBitSets, const UARTConfig &config) : parityErrorsDetected(0), frameErrorsDetected(0)
{
    decodeQueue(transmittedBitSets, config);
    validateFrames(framesReceived, config);
}

void UARTReceiver::decodeQueue(std::queue<std::vector<bool>> bitSets, const UARTConfig &config)
{
    while (!bitSets.empty())
    {
        framesReceived.push(UARTFrame(bitSets.front(), config));
        bitSets.pop();
    }
}

void UARTReceiver::validateFrames(std::queue<UARTFrame> frames, const UARTConfig &config)
{
    while (!frames.empty())
    {
        parityErrorsDetected += frames.front().checkParityError(frames.front().getBits(), config);
        frameErrorsDetected += frames.front().checkFrameError(frames.front().getBits(), config);
        frames.pop();
    }
}

const std::queue<UARTFrame> &UARTReceiver::getReceivedFrames() const
{
    return framesReceived;
}

const int UARTReceiver::getDetectedParityErrors() const
{
    return parityErrorsDetected;
}

const int UARTReceiver::getDetectedFrameErrors() const
{
    return frameErrorsDetected;
}