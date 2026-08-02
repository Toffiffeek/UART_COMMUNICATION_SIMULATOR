/**/
#pragma once


class UARTConfig{
private:
    int baudRate;
    int stopBits;
    bool parityEnabled;
public:
    UARTConfig();
    void displayMenu() const;
};