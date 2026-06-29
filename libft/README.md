*This project has been created as part of the 42 curriculum by guicarva.*

# Libft

## Description
Libft is a foundational project in the 42 curriculum that consists of recreating a custom C standard library. The goal is to deepen understanding of low-level programming concepts such as memory management, string manipulation, and data structures.

This project involves reimplementing a set of standard C library functions, as well as developing additional utility functions that will be reused in future projects. It serves as a personal toolbox of reliable and reusable code.

## Features
- Reimplementation of standard libc functions (e.g., `strlen`, `memcpy`, `atoi`)
- Additional utility functions for string and memory handling
- Linked list manipulation functions
- Modular and reusable static library (`libft.a`)

## Library Overview

### Character Functions
- ft_isalpha
- ft_isdigit
- ft_isalnum
- ft_isascii
- ft_isprint
- ft_toupper
- ft_tolower

### String Functions
- ft_strlen
- ft_strchr
- ft_strrchr
- ft_strncmp
- ft_strlcpy
- ft_strlcat
- ft_strnstr
- ft_strdup

### Memory Functions
- ft_memset
- ft_bzero
- ft_memcpy
- ft_memmove
- ft_memchr
- ft_memcmp
- ft_calloc

### Conversion Functions
- ft_atoi

### Additional Functions
- ft_substr
- ft_strjoin
- ft_strtrim
- ft_split
- ft_itoa
- ft_strmapi
- ft_striteri
- ft_putchar_fd
- ft_putstr_fd
- ft_putendl_fd
- ft_putnbr_fd

### Linked List Functions
- ft_lstnew
- ft_lstadd_front
- ft_lstsize
- ft_lstlast
- ft_lstadd_back
- ft_lstdelone
- ft_lstclear
- ft_lstiter
- ft_lstmap

## Instructions

### Compilation
make

### Clean object files
make clean

### Full clean
make fclean

### Recompile
make re

### Usage
Include in your code:
#include "libft.h"

Compile with:
gcc your_file.c libft.a -o your_file_name

## Resources

### Documentation
- The C Programming Language — Kernighan & Ritchie
- GNU C Library Documentation
- POSIX documentation
- man pages

### AI Usage
AI tools (ChatGPT) were used for:
- Clarifying concepts and edge cases
- Structuring documentation

All code was written and tested manually in accordance with 42 standards.

## Notes
This library will be reused in future 42 projects as a base toolkit.
