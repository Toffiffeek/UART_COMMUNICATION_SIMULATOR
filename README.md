# UART Communication Simulator

A simple C++ application that simulates UART (Universal Asynchronous Receiver/Transmitter) communication between two devices.

## Features

- UART configuration
  - Baud rate
  - Parity
  - Stop bits
- ASCII to binary conversion
- UART frame generation
- Frame-by-frame transmission simulation
- Random transmision errors
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

The simulator visualizes UART transmission in real time based on the configured baud rate.

For readability, the transmission is intentionally slowed down by a factor of 1000 compared to the real UART transmission time.

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
0 00010010 0 1
0 10010110 0 1
```

Output:

```
TX -> 0 ->RX
TX -> 0 ->RX
TX -> 0 ->RX
TX -> 0 ->RX
...
==================================
         TANSMISION SUMMARY 
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