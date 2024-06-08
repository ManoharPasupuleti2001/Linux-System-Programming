# Process Management in Linux System Programming

## Introduction

Process management is a crucial aspect of Linux system programming. It involves creating, scheduling, and terminating processes, as well as managing their resources and communication. This README provides an overview of key concepts, tools, and code examples to help you understand and implement process management in Linux.

## Table of Contents

- [Introduction](#introduction)
- [Prerequisites](#prerequisites)
- [Key Concepts](#key-concepts)
  - [Processes](#processes)
  - [Process States](#process-states)
  - [Process Control](#process-control)
- [System Calls for Process Management](#system-calls-for-process-management)
  - [fork()](#fork)
  - [exec()](#exec)
  - [wait()](#wait)
  - [exit()](#exit)
- [Example Code](#example-code)
- [Further Reading](#further-reading)
- [Contributing](#contributing)
- [License](#license)

## Prerequisites

- Basic understanding of C programming.
- Familiarity with Linux command-line interface.
- Basic knowledge of operating system concepts.

## Key Concepts

### Processes

A process is an instance of a running program. Each process has its own address space, memory, and resources. Linux processes are identified by unique process IDs (PIDs).

### Process States

Processes in Linux can be in one of several states:
- **Running**: The process is currently being executed.
- **Waiting**: The process is waiting for an event or resource.
- **Stopped**: The process has been stopped, usually by receiving a signal.
- **Zombie**: The process has terminated, but its entry still exists in the process table.

### Process Control

Process control involves creating, modifying, and terminating processes. This includes assigning CPU time, handling process synchronization, and managing process communication.

## System Calls for Process Management

### `fork()`

`fork()` creates a new process by duplicating the current process. The new process is called the child process, and the original process is the parent. The child process gets a unique PID.

```c
pid_t pid = fork();
if (pid == 0) {
    // Child process
} else if (pid > 0) {
    // Parent process
} else {
    // Fork failed
}
```

### `exec()`

`exec()` replaces the current process image with a new process image. It is used to run a new program within the current process.

```c
execl("/bin/ls", "ls", NULL);
```

### `wait()`

`wait()` makes the parent process wait until all of its child processes have terminated. It can be used to retrieve the exit status of a child process.

```c
int status;
pid_t pid = wait(&status);
```

### `exit()`

`exit()` terminates the current process and returns an exit status to the parent process.

```c
exit(0);
```

## Example Code

### Fork and Exec Example

```c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        execl("/bin/ls", "ls", NULL);
    } else if (pid > 0) {
        // Parent process
        wait(NULL);
        printf("Child process finished\n");
    } else {
        // Fork failed
        perror("fork");
        return 1;
    }

    return 0;
}
```

## Further Reading

- [Linux Programmer's Manual](https://man7.org/linux/man-pages/section2.html)


