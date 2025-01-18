# Minitalk

## Overview

**Minitalk** is a project that implements client-server communication using UNIX signals. The goal is to send and receive messages bit by bit through signals, ensuring synchronization and proper handling of asynchronous events.

This project is a great way to learn about inter-process communication (IPC), signal handling, and synchronization techniques.

---

## Key Concepts

### What Are Signals?

A **signal** is a software interrupt sent to a process to notify it of an event. Examples include process termination, memory access violations, or user-defined actions. Signals play a critical role in managing inter-process communication.

### Why Signals for IPC?

Signals are lightweight and efficient for simple communication like notifying a process about an event. In Minitalk, signals are used to:

- **Transmit data:** Use `SIGUSR1` and `SIGUSR2` to represent binary data (`0` and `1`).
- **Synchronize processes:** Ensure the server correctly receives and processes each bit.

---

## Key Features

- **Client-Server Communication:**  
  The client sends messages to the server using `SIGUSR1` and `SIGUSR2`. The server decodes these signals into readable text.
  
- **Binary Transmission:**  
  Messages are sent bit by bit, making this a good introduction to low-level communication protocols.

- **Signal Handlers:**  
  Custom handlers are implemented to manage incoming signals and handle them efficiently.

- **Synchronization:**  
  The project avoids race conditions and ensures the server processes signals in order.

---

## Why `SIGUSR1` and `SIGUSR2`?

These signals are reserved for user-defined purposes and don't interfere with system-defined signals like `SIGINT` or `SIGKILL`. In Minitalk:

- **`SIGUSR1`** represents binary `0`.  
- **`SIGUSR2`** represents binary `1`.  

This binary communication protocol ensures precise transmission and avoids ambiguity.

---

## How Signals Are Handled

### Signal Handlers
A **signal handler** is a function executed in response to a signal. For example:

```c
void handle_signal(int signum) {
    if (signum == SIGUSR1) {
        // Handle binary '0'
    } else if (signum == SIGUSR2) {
        // Handle binary '1'
    }
}

