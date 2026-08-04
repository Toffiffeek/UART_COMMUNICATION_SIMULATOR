#include "ConsoleUI.hpp"
#include "Enums.hpp"
#include <iostream>
#include <stdexcept>
#include <limits>

ConsoleUI::ConsoleUI() = default;

void ConsoleUI::displayMenu() const
{
    std::cout << "==================================\n";
    std::cout << "     UART CONFIGURATION MENU      \n";
    std::cout << "==================================\n";
}

void ConsoleUI::displayBaudRateMenu() const
{
    std::cout << "PRESS THE NUMBER TO SELECT DESIRED BAUD RATE:\n";
    std::cout << "1. 9600 BPS\n";
    std::cout << "2. 19200 BPS\n";
    std::cout << "3. 38400 BPS\n";
    std::cout << "4. 57600 BPS\n";
    std::cout << "5. 115200 BPS\n";
}

void ConsoleUI::displayParityMenu() const
{
    std::cout << "PRESS NUMBER TO SELECT DESIRED PARITY MODE:\n";
    std::cout << "1. EVEN\n";
    std::cout << "2. ODD\n";
    std::cout << "3. NONE\n";
}

void ConsoleUI::displayStopBitsMenu() const
{
    std::cout << "PRESS THE NUMBER TO SELECT DESIRED NUMBER OF STOP BITS\n";
    std::cout << "1. ONE\n";
    std::cout << "2. TWO\n";
}

void ConsoleUI::displayConfig(const UARTConfig &config) const
{
    std::cout << "BAUD RATE: " << baudRateToInt(config.getBaudRate()) << " BPS\n";
    std::cout << "NUMBER OF STOP BITS: " << stopBitsToInt(config.getStopBits()) << "\n";
    std::cout << "PARITY MODE: " << parityModeToString(config.getParity()) <<"\n";
}

BaudRate ConsoleUI::convertChoiceToBaudRate(int choice) const
{
    switch (choice)
    {
    case 1:
        return BaudRate::B9600;
    case 2:
        return BaudRate::B19200;
    case 3:
        return BaudRate::B38400;
    case 4:
        return BaudRate::B57600;
    case 5:
        return BaudRate::B115200;
    default:
        throw std::invalid_argument("INVALID CHOICE");
    }
}

ParityMode ConsoleUI::convertChoiceToParity(int choice) const
{
    switch (choice)
    {
    case 1:
        return ParityMode::Even;
    case 2:
        return ParityMode::Odd;
    case 3:
        return ParityMode::None;
    default:
        throw std::invalid_argument("INVALID CHOICE");
    }
}

StopBits ConsoleUI::convertChoiceToStopBits(int choice) const
{
    switch (choice)
    {
    case 1:
        return StopBits::One;
    case 2:
        return StopBits::Two;
    default:
        throw std::invalid_argument("INVALID CHOICE");
    }
}

int ConsoleUI::getIntInput(int min, int max) const
{
    while (true)
    {
        int number;
        std::cout << "ENTER NUMBER: ";
        std::cin >> number;
        if (std::cin.fail() || number > max || number < min)
        {
            std::cout << "INVALID NUMBER\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return number;
    }
}

std::string ConsoleUI::getStringInput() const
{
    while (true)
    {
        std::string message;
        std::cout << "ENTER MESSAGE: ";
        std::getline(std::cin, message);
        if (message.empty())
        {
            std::cout << "MESSAGE CANNOT BE EMPTY\n";
            continue;
        }
        return message;
    }
}

BaudRate ConsoleUI::getBaudRateChoice() const
{
    displayBaudRateMenu();
    int choice = getIntInput(1, 5);
    return convertChoiceToBaudRate(choice);
}

ParityMode ConsoleUI::getParityChoice() const
{
    displayParityMenu();
    int choice = getIntInput(1, 3);
    return convertChoiceToParity(choice);
}

StopBits ConsoleUI::getStopBitsChoice() const
{
    displayStopBitsMenu();
    int choice = getIntInput(1, 2);
    return convertChoiceToStopBits(choice);
}