# 🗣️ Minitalk

A project that implements inter-process communication using UNIX signals.

## Overview

Minitalk is a client-server communication program that uses only two UNIX signals (`SIGUSR1` and `SIGUSR2`) to transmit messages between processes. This project serves as an introduction to inter-process communication (IPC) and signal handling in UNIX systems.

The goal is to create two programs:
- **Server**: Receives and displays messages from clients
- **Client**: Sends messages to the server using the server's PID

## How It Works

### Signal-Based Communication

The communication system works by converting text into binary and transmitting it bit by bit using signals:

- `SIGUSR1` represents a binary **1**
- `SIGUSR2` represents a binary **0**

### The Process

1. **Server Initialization**
   - Server starts and displays its Process ID (PID)
   - Sets up signal handlers for `SIGUSR1` and `SIGUSR2`
   - Enters an infinite loop waiting for signals

2. **Client Message Transmission**
   - Client takes the server's PID and a message as arguments
   - Each character is converted to its binary representation (8 bits)
   - For each bit:
     - If bit is `1`, send `SIGUSR1` to server
     - If bit is `0`, send `SIGUSR2` to server
   - Waits for server acknowledgment before sending the next bit

3. **Server Message Reception**
   - Server receives signals one at a time
   - Reconstructs each character bit by bit
   - Once 8 bits are received, the complete character is printed
   - Server sends acknowledgment signal back to client
   - Process continues until the entire message is received

### Binary Transmission Example

For example, the letter 'A' (ASCII 65):
```
'A' = 01000001 in binary

Bit 0: 0 → Send SIGUSR2
Bit 1: 1 → Send SIGUSR1
Bit 2: 0 → Send SIGUSR2
Bit 3: 0 → Send SIGUSR2
Bit 4: 0 → Send SIGUSR2
Bit 5: 0 → Send SIGUSR2
Bit 6: 0 → Send SIGUSR2
Bit 7: 1 → Send SIGUSR1
```

## Installation

```bash
# Clone the repository
git clone https://github.com/dajose-p/minitalk
cd minitalk

# Compile the project
make

# This will create two executables: server and client
```

## Usage

### Starting the Server

```bash
./server
```

The server will display its PID, which you'll need for the client:
```
Server PID: 12345
```

### Sending Messages from Client

In a new terminal:

```bash
./client [server_pid] "Your message here"
```

Example:
```bash
./client 12345 "Hello, World!"
```

The message will appear in the server's terminal:
```
Server PID: 12345
Hello, World!
```

### Sending Unicode Characters

The program supports Unicode characters, emojis, and various character sets:

```bash
./client 12345 "Hello 世界! 🌍"
./client 12345 "مرحبا"
```

## Key Concepts

### UNIX Signals

Signals are software interrupts that provide a way for processes to communicate. In this project:
- Signals are asynchronous notifications sent to a process
- `kill()` function sends signals between processes
- Signal handlers catch and process incoming signals

### Bitwise Operations

The project relies heavily on bitwise operations:
- **Left shift (`<<`)**: Extract bits from characters
- **Right shift (`>>`)**: Position bits correctly
- **OR operator (`|`)**: Set bits to 1
- **AND operator (`&`)**: Check bit values
- **NOT operator (`~`)**: Clear bits to 0

### Process Communication

- **PID**: Process Identifier, unique number for each running process
- **Signal handlers**: Functions that execute when signals are received

## Performance

A well-optimized implementation can transmit 100 characters in approximately 0.015 seconds, far exceeding the 1-second requirement.

## Resources

- `man signal`
- `man sigaction`
- `man kill`
- Understanding bitwise operations in C
- Inter-process communication in UNIX
