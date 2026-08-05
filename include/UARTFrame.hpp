/**/
#pragma once

#include <iostream>
#include <vector>

class UARTFrame
{
private:
    std::string message;
    std::vector<bool> frame;

public:
    UARTFrame(std::string message, std::vector<bool> frame);

    std::string getMessage() const;
    std::vector<bool> getFrame() const;
    void setMessage(std::string message);
    void setFrame(std::vector<bool> frame);
    std::vector<bool> reverseBits(std::vector<bool> bits);
    std::vector<bool> addStopBits(std::vector<bool> bits);
    std::vector<bool> addStartBits(std::vector<bool> bits);
    std::vector<bool> addParityBit(std::vector<bool> bits);
};