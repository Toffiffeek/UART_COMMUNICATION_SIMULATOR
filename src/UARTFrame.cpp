/*Implementation of methods declared in UARTFrame.hpp*/

#include "UARTFrame.hpp"
#include <iostream>
#include <vector>

UARTFrame::UARTFrame(std::string message, std::vector<bool> frame) : message(message), frame(frame)
{
}

std::string UARTFrame::getMessage() const
{
    return message;
}

std::vector<bool> UARTFrame::getFrame() const
{
    return frame;
}

void UARTFrame::setMessage(std::string message){
    this->message = message;
}
void UARTFrame::setFrame(std::vector<bool> frame){
    this->frame = frame;
}