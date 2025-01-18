# Minitalk

**Note:** This project is **not completed yet**.

## Overview

Minitalk is a project designed to explore inter-process communication using UNIX signals. It involves implementing a client-server communication protocol where messages are transmitted bit by bit using `SIGUSR1` and `SIGUSR2`.

---

## What Are Signals?

A **signal** is an interruption notifying a process about an event, often prompting it to pause and handle the occurrence before resuming. Signals are essential for:

- Informing a process about events like suspension, system calls, or faults.
- Preventing race conditions or deadlocks by coordinating actions.

---

## Key System Calls for Signal Handling

- **`signal()`**: Sets a simple signal handler.
- **`sigaction()`**: Advanced, thread-safe method to handle signals.
- **`kill()`**: Sends a signal to a specific process.
- **`raise()`**: Sends a signal to the current process.
- **`pause()`**: Waits for a signal.
- **`sigpending()`**: Checks pending signals (*not allowed in this project*).

### What Is a Signal Handler?

A signal handler is a function defined in your program to handle a specific signal. When a signal is delivered, the handler executes to respond to the event. Signal handlers allow custom actions to be taken when a signal is received.

---

## Why Use `SIGUSR1` and `SIGUSR2`?

- These signals are user-defined and do not conflict with standard system signals.
- In Minitalk, they are used to transmit binary data (bits of the message) from the client to the server.
- The client sends these signals using the `kill()` function, and the server interprets them as `0` or `1`.

---

## Why Use `volatile sig_atomic_t`?

The `volatile sig_atomic_t` type is essential for:

1. **Preventing conflicts**: Ensures no corrupted data is written due to simultaneous signal handling.
2. **Atomic operations**: Guarantees that the variable is read or written in a single operation.
3. **Preventing optimizations**: `volatile` ensures the compiler always fetches the latest value.

---

## Standard Signals to Know

- **`SIGINT` (2)**: Sent when the user presses `Ctrl+C`.
- **`SIGTERM` (15)**: Gracefully terminates a process.
- **`SIGHUP` (1)**: Sent when a terminal is closed.
- **`SIGKILL` (9)**: Immediately terminates a process (cannot be ignored or caught).
- **`SIGSEGV` (11)**: Indicates an invalid memory access (*segfault*).

---

## Signal Mask and Blocking (`sigprocmask`)

A **signal mask** allows control over which signals are temporarily blocked. Blocking signals ensures that signal handlers don't interfere with sensitive operations.  

**Function Prototype:**
```c
#include <signal.h>
int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);

