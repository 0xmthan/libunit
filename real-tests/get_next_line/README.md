*This project has been created as part of the 42 curriculum by mtaheri*

# get_next_line

## Description

**get_next_line** is a C function that reads a file descriptor line by line.
Each call to `get_next_line()` returns the next line from the given file descriptor,
including the terminating `\n` when present, or `NULL` when there is nothing left to read
or an error occurs.

This project focuses on:
- Understanding **static variables**
- Working with **file descriptors**
- Managing **dynamic memory safely**
- Reading input efficiently using a configurable buffer size

---

## Prototype

```c
char *get_next_line(int fd);
```

---

## How It Works (Algorithm Overview)

This implementation is based on a **stash** mechanism:

1. A static string (`stash`) keeps unread data between function calls.
2. Data is read from `fd` into a buffer of size `BUFFER_SIZE`.
3. The buffer is appended to the stash until a newline (`\n`) is found or EOF is reached.
4. Once a newline exists:
   - The line is extracted from the stash
   - The remaining part is kept for the next call
5. Memory is freed correctly on errors or end of file.

This approach ensures:
- Minimal reads
- No data loss between calls
- Compatibility with very small or very large `BUFFER_SIZE` values

---

## Files

- `get_next_line.c` – Core logic
- `get_next_line.h` – Function prototype and macros

---

## Compilation

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c
```

You can change `BUFFER_SIZE` to any positive value.

---

## Usage Example

```c
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

---

## Bonus

- Handle **multiple file descriptors** simultaneously
- Use **only one static variable**

---

## Resources

- [gibbontech's get_next_line notes](https://www.gibbontech.com/ecole42/get_next_line/index.html)
- [File Descriptors – Educational Innovation](https://youtu.be/WCrTRPu1bQk)
- `man 2 read`
- [Static Variables in C – GeeksForGeeks](https://www.geeksforgeeks.org/c/static-variables-in-c/)

---

## Notes on AI Usage

AI was used as a **documentation and explanation aid only**.
The algorithm design and implementation decisions were made manually
to comply with 42 learning principles.
