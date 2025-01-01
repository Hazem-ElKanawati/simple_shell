# Simple Shell

**Simple Shell** is a custom implementation of a Unix command-line interpreter, commonly known as a shell. This project was developed as part of the curriculum at ALX Software Engineering Program to deepen understanding of system calls, process creation, and user input handling in C.

## Table of Contents
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Built With](#built-with)
- [Authors](#authors)
- [License](#license)

## Features
- Executes commands with arguments, such as `ls -l`
- Handles the `PATH` environment variable
- Implements built-in commands like `exit`
- Supports input redirection
- Handles command separators (`;`)

## Installation
To compile the simple_shell, ensure you have `gcc` installed and run:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o simple_shell
```

## Usage
After compilation, start the shell with:

```bash
./simple_shell
```

You can then enter commands as you would in a standard Unix shell.

## Built With
- C Programming Language
- GCC Compiler
- Unix System Calls

## Authors
- **Hazem El-Kanawati** - [Hazem-ElKanawati](https://github.com/Hazem-ElKanawati)


