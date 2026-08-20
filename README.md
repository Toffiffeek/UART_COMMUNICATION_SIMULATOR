# UART Communication Simulator

A simple C++ application that simulates UART (Universal Asynchronous Receiver/Transmitter) communication between two devices.

## Project Goal

This project was created as an educational UART communication simulator.
Its purpose is to explore the principles of asynchronous serial
communication and apply object-oriented programming concepts in C++.

## Problem Statement

UART is a relatively simple communication protocol commonly used in embedded systens, but the individual
steps involved in transmitting a character are often hidden by hardware
abstraction.

The project addresses this by providing a software model of the
transmission process, making the structure of UART frames, bit ordering,
parity, stop bits, errors, and baud rate effects observable.

## Features

- UART configuration
  - Baud rate
  - Parity
  - Stop bits
- 8-bit character encoding
- UART frame generation
- Frame-by-frame transmission simulation
- Random transmission errors
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

## Transmission Visualization

The simulator visualizes the transmission of individual UART bits based on the configured baud rate.

For readability, the visualization is intentionally slowed down by a factor of 1000 compared to the real UART transmission time.

This scaling affects only the console visualization and does not change the simulated UART logic.

For example:
- 9600 baud → approximately 104 ms per bit
- 19200 baud → approximately 52 ms per bit
- 115200 baud → approximately 8.7 ms per bit

## Example

Input:

```
MESSAGE: Hi
```

Generated frames:

```
 START |   DATA   | PARITY | STOP
   0   | 00010010 |   0    |  1
   0   | 10010110 |   0    |  1
```

Output:

```
TX -> 0 -> RX
TX -> 0 -> RX
TX -> 0 -> RX
TX -> 0 -> RX
...
==================================
         TANSMISSION SUMMARY 
==================================      
RECEIVED: Hi
FRAMES SENT: 2
PARITY ERRORS DETECTED: 0
FRAME ERRORS DETECTED: 0
==================================
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

- Multiple UART devices
- Logging to file
- GUI version
- Unit tests

## Author

MIKOŁAJ RUTECKI