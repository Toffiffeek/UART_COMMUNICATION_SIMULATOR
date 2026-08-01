# UART Communication Simulator

A simple C++ application that simulates UART (Universal Asynchronous Receiver/Transmitter) communication between two devices.

## Features

- UART configuration
  - Baud rate
  - Data bits
  - Parity
  - Stop bits
- ASCII to binary conversion
- UART frame generation
- Bit-by-bit transmission simulation
- Frame validation
- Console output with transmission summary

## Technologies

- C++
- CMake

## Project Structure

```
UART-Communication-Simulator/
│
├── include/
├── src/
├── CMakeLists.txt
└── README.md
```

## Example

Input:

```
Message: Hi
```

Generated frame:

```
0 01001000 0 1
```

Output:

```
Sending...

TX -> 0
TX -> 0
TX -> 1
TX -> 0
...

Received: Hi
```

## How to Build

```bash
cmake -S . -B build
cmake --build build
```

Run:

```bash
./build/UARTSimulator
```

## Future Improvements

- Random transmission errors
- Multiple UART devices
- Logging to file
- GUI version
- Unit tests

## Author

MIKOŁAJ RUTECKI