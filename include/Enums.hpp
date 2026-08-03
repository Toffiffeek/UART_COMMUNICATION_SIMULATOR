#pragma once

enum class BaudRate{
    B9600 = 9600,
    B19200 = 19200,
    B38400 = 38400,
    B57600 = 57600,
    B115200 = 115200,
};

enum class ParityMode{
    Even,
    Odd,
    None,
};

enum class StopBits{
    One = 1,
    Two = 2,
};
