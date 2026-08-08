# UART Communication Simulator

A simple C++ application that simulates UART (Universal Asynchronous Receiver/Transmitter) communication between two devices.

## Features

- UART configuration
  - Baud rate
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
├── .gitignore
├── CMakeLists.txt
├── LICENSE
└── README.md
```

## Example

Input:

```
MESSAGE: Hi
```

Generated frames:

```
0 00010010 0 1
0 10010110 0 1
```

Output:

```
Sending...

TX -> 0
TX -> 0
TX -> 0
TX -> 0
...

RECEIVED: Hi
```

## How to Build

```bash
cmake -S . -B build
cmake --build build
```

Run:

```bash
./build/UART_COMMUNICATION_SIMULATOR.exe
```

## Future Improvements

- Random transmission errors
- Multiple UART devices
- Logging to file
- GUI version
- Unit tests

## Author

MIKOŁAJ RUTECKI