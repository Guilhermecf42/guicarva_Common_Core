*This project has been created as part of the 42 curriculum by guicarva.*

# Get Next Line

Project developed at 42 School with the goal of implementing a function capable of reading one line at a time from a file descriptor.

---

## Description

The **get_next_line** project from 42 aims to deepen knowledge about:

* File descriptor manipulation
* File reading in C
* Dynamic memory management
* Static variables
* Utility functions
* Buffer handling

The main function of the project must return a complete line at each call, including the `\n` character when it exists.

---

### Function prototype

```c
char *get_next_line(int fd);
```

### Parameters

| Parameter |            Description              |
| --------- | ----------------------------------- |
|   `fd`    | File descriptor of the file to read |

### Return value

* Returns the next line read from the file
* Returns `NULL` when reaching the end of the file or in case of error

---

### How it works

The function reads the file content using a buffer whose size is defined by the macro:

```c
BUFFER_SIZE
```

The content is temporarily stored until a full line is found.

At each call:

1. The file is read in chunks
2. The content is accumulated
3. The next line is extracted
4. The remaining content is stored for the next execution

---

### Project structure

```bash
.
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
├── get_next_line_bonus.c
├── get_next_line_utils_bonus.c
├── get_next_line_bonus.h
└── README.md

```

---

## Instructions

Clone the repository:

```bash
git clone <repository>
cd get_next_line
```

Compile the project:

```bash
cc -Wall -Wextra -Werror get_next_line.h get_next_line_utils.c get_next_line.c <your_main>
```

Compile with bonus:

```bash
cc -Wall -Wextra -Werror get_next_line_bonus.h get_next_line_utils_bonus.c get_next_line_bonus.c <your_main>
```

---

### Usage example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		printf("test: %s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
```

---

### Usage example bonus

```c
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line1;
	char	*line2;
	char	*line3;

	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
		return (1);
	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	line3 = get_next_line(fd3);
	while (line1 || line2 || line3)
	{
		if (line1)
		{
			printf("test 1: %s", line1);
			free(line1);
			line1 = get_next_line(fd1);
		}
		if (line2)
		{
			printf("test 2: %s", line2);
			free(line2);
			line2 = get_next_line(fd2);
		}
		if (line3)
		{
			printf("test 3: %s", line3);
			free(line3);
			line3 = get_next_line(fd3);
		}
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
```

---

## Resources

During the development of this project, the following resources were used for learning and reference purposes:

Documentation
The Open Group — read() Manual
Linux man pages — open(2)
Linux man pages — static variables in C
GNU C Documentation
Tutorials and Articles
GeeksforGeeks — File Handling in C
GeeksforGeeks — Static Variables in C
42 GitBook — Get Next Line Overview

---

### AI Usage

Artificial Intelligence tools were used as learning and support resources during the development of this project.

AI-assisted tasks
README structure and formatting
Documentation writing
English grammar correction
Understanding edge cases and debugging strategies
Clarification of concepts related to:
static variables
memory management
file descriptors
buffer handling
Important note

All implementation logic, code structure, debugging, and final validation were completed manually by the author in accordance with the 42 School rules and learning objectives.
