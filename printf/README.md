*This project has been created as part of the 42 curriculum by guicarva.*

# ft_printf

A custom implementation of the standard C `printf` function, developed as part of the 42 curriculum.

## Description

The goal of `ft_printf` is to recreate the behavior of the original `printf` function, handling different format specifiers and variable arguments using only authorized functions.

This project helps improve knowledge in:

- Variadic functions (`stdarg.h`)
- String parsing
- Type conversion
- Memory handling
- Modular programming in C

### Features

The project supports the following conversions:

| Conversion |      Description      |
|------------|-----------------------|
|    `%c`    |       Character       |
|    `%s`    |        String         |
|    `%p`    |    Pointer address    |
|    `%d`    |    Decimal integer    |
|    `%i`    |        Integer        |
|    `%u`    |    Unsigned integer   |
|    `%x`    | Lowercase hexadecimal |
|    `%X`    | Uppercase hexadecimal |
|    `%%`    |     Percent symbol    |

### Project Structure

ft_printf/
├── ft_printf.c
├── ft_printf.h
├── ft_putchar.c
├── ft_putnbr_hexa.c
├── ft_putnbr_pointer.c
├── ft_putnbr_unsigned.c
├── ft_putnbr.c
├── ft_putstr.c
├── Makefile
└── README.md

## Instructions

### Compilation
make
This will generate the library:
libftprintf.a

### Clean object files
make clean

### Full clean
make fclean

### Recompile
make re

### Usage
Include the header in your project:
#include "libftprintf.a"

Compile with:
cc your_file.c libftprintf.a -o your_file_name

Example:

#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "world");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hexadecimal: %x\n", 255);
    return (0);
}

Example Output:

Hello world!
Number: 42
Hexadecimal: ff

## Resources

### Documentation
- The C Programming Language — Kernighan & Ritchie
- man page

### AI Usage
AI tools (ChatGPT) were used for:
- Clarifying concepts and edge cases
- Structuring documentation

All code was written and tested manually in accordance with 42 standards.

## Notes
This library will be reused in future 42 projects as a base toolkit.
