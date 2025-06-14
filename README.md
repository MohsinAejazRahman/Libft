# 📚 libft – Custom C Library
`libft` is the first project in the 42 core curriculum. It requires you to reimplement standard C library functions from `<ctype.h>`, `<stdlib.h>`, `<string.h>` and `<unistd.h>` along with some custom funcrtions. Here you must organize them into a reusable static library. This `README` will help you **understand the theory and mechanisms of C** to help you write these functions which have been grouped by category.

> 🔍 **Note:**  
This document is **not a tutorial** and does **not explain how to implement code** for each function. Instead, it provides a high-level overview and theory to help you understand the core features of the C language. To write your own implementation, refer to the documentation within each individual `.c` file in the `srcs/` directory. There you will find documentation on the specific function.


---
# 📑 Table of Contents

- [Project Structure](#project-structure)
- [Library Functions](#library-functions)
  - [Integers](#integers)
  - [Characters and Strings](#-characters-and-strings)
  - [Pointers and Memory](#-pointers-and-memory)
  - [File Descriptors](#-file-descriptors)
  - [Linked Lists](#linked-lists)
- [Makefile](#makefile)

--- 
# 🗂 Project Structure

    📁 libft/
    ├── Makefile
    ├── README.md
    └── srcs/
        │   Character checks:
        ├── ft_isalpha.c        (ctype.h)       - Character classification
        ├── ft_isdigit.c        (ctype.h)       - Character classification
        ├── ft_isalnum.c        (ctype.h)       - Character classification
        ├── ft_isascii.c        (ctype.h)       - Character classification
        ├── ft_isprint.c        (ctype.h)       - Character classification
        │
        │   String functions:
        ├── ft_strlen.c         (string.h)      - String length calculation
        ├── ft_strdup.c         (string.h)      - String duplication
        ├── ft_strchr.c         (string.h)      - Locate character in string
        ├── ft_strrchr.c        (string.h)      - Locate last occurrence of character
        ├── ft_strncmp.c        (string.h)      - Compare strings up to n characters
        ├── ft_strnstr.c        (string.h)      - Locate substring in string (bounded)
        ├── ft_strlcpy.c        (string.h)      - Copy string with size limit
        ├── ft_strlcat.c        (string.h)      - Concatenate string with size limit
        ├── ft_strjoin.c        (custom)        - Join two strings
        ├── ft_strtrim.c        (custom)        - Trim characters from string ends
        ├── ft_substr.c         (custom)        - Extract substring
        ├── ft_strmapi.c        (custom)        - Map function to string chars
        ├── ft_striteri.c       (custom)        - Iterate function over string chars
        │
        │   Memory functions:
        ├── ft_bzero.c          (strings.h)     - Zero memory block
        ├── ft_memset.c         (string.h)      - Fill memory with constant byte
        ├── ft_memcpy.c         (string.h)      - Copy memory area
        ├── ft_memmove.c        (string.h)      - Copy memory area safely (overlapping)
        ├── ft_memchr.c         (string.h)      - Locate byte in memory
        ├── ft_memcmp.c         (string.h)      - Compare memory areas
        │
        │   Conversion & allocation:
        ├── ft_atoi.c           (stdlib.h)      - Convert string to integer
        ├── ft_itoa.c           (custom)        - Convert integer to string
        ├── ft_calloc.c         (stdlib.h)      - Allocate and zero-initialize memory
        │
        │   Output functions:
        ├── ft_putchar_fd.c     (unistd.h)      - Write char to file descriptor
        ├── ft_putstr_fd.c      (unistd.h)      - Write string to file descriptor
        ├── ft_putendl_fd.c     (unistd.h)      - Write string with newline
        ├── ft_putnbr_fd.c      (unistd.h)      - Write number to file descriptor
        │
        │   Character case:
        ├── ft_tolower.c        (ctype.h)       - Convert character to lowercase
        ├── ft_toupper.c        (ctype.h)       - Convert character to uppercase
        │
        │   String splitting:
        ├── ft_split.c          (custom)        - Split string into array by delimiter
        │
        │   linked list:
        ├── ft_lstnew_bonus.c       (custom)    - Create new linked list element
        ├── ft_lstadd_front_bonus.c (custom)    - Add element at list start
        ├── ft_lstadd_back_bonus.c  (custom)    - Add element at list end
        ├── ft_lstdelone_bonus.c    (custom)    - Delete one element
        ├── ft_lstclear_bonus.c     (custom)    - Clear entire list
        ├── ft_lstiter_bonus.c      (custom)    - Iterate function over list
        ├── ft_lstmap_bonus.c       (custom)    - Map function to list elements
        ├── ft_lstlast_bonus.c      (custom)    - Get last element of list
        ├── ft_lstsize_bonus.c      (custom)    - Get size of list
        │
        └── libft.h                  (custom)        - Header file with prototypes and macros




---
# 🧰 Library Functions

## 🔢 Integers
```c
short               s;      // 2 bytes (16 bits): Range -32,768 to 32,767
unsigned short      s;      // 2 bytes (16 bits): Range 0 to 65,535
int                 i;      // 4 bytes (32 bits): Range -2,147,483,648 to 2,147,483,647
unsigned int        ui;     // 4 bytes (32 bits): Range 0 to 4,294,967,295
long                l;      // 8 bytes (64 bits): Range -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
unsigned long       ul;     // 8 bytes (64 bits): Range 0 to 18,446,744,073,709,551,615
unsigned long int   uli;    // 8 bytes (64 bits): Range 0 to 18,446,744,073,709,551,615
unsigned long long  ull;    // 8 bytes (64 bits): Range 0 to 18,446,744,073,709,551,615
```

## 🆎 Characters
```c
char            c;  // 1 byte (8 bites): Range -128 to 127 or 0 to 255
unsigned char   c;  // 1 byte (8 bites): Range 0 to 255
```

## 🧠 Pointers and Memory
```c
void    *v;
int     *i;
char    *s;
```

## 📤 File Descriptors

A **file descriptor (FD)** is a non-negative integer used by the operating system to identify an open file, socket, pipe, or other I/O (input/output) resource. File descriptors act as an abstract indicator (or handle) through which a program can perform read/write operations.

They can be thought of as IDs for open files and streams. Your program reads from or writes to a file descriptor instead of dealing directly with hardware or file content.

**Upon program startup, a Unix-like OS automatically opens 3 file descriptors:**
|  File Descriptor    | Value | <unistd.h>     | <stdio.h>   | Default Target | Common Usage                            |
|---------------------|-------|----------------|-------------|----------------|-----------------------------------------|
| `Standard Input`    | `0`   | STDIN_FILENO   |    stdin    | Keyboard       | `read()`, `scanf()`, `getchar()`        |
| `Standard Output`   | `1`   | STDOUT_FILENO  |    stdout   | Terminal       | `write()`, `printf()`                   |
| `Standard Error`    | `2`   | STDERR_FILENO  |    stderr   | Terminal       | `write()`, `fprintf(stderr, ...)` |

**File descriptors (FDs) numbered 3 and above are dynamically allocated by the operating system whenever a new file or socket is opened.** When a file is opened, the OS assigns the lowest available FD greater than 2. Each process maintains its own file descriptor table, which is managed by the kernel. In this table, each index represents a file descriptor and points to an entry in the file table. This file table entry contains:

- The current file offset (i.e., the read/write position)  
- The file access mode (read, write, or both)  
- A pointer to the vnode/inode representing the actual file  
- File status flags (for example, `O_APPEND`)  

> 🔍 **Note:**  
> Each process tracks its own set of file descriptors independently. This means that if the same file is opened in two different processes, each process can have a different FD referring to that file. The assigned FD is always the smallest available number greater than 2 in the context of that particular process.

Common File Descriptor Functions

| Function           | Purpose                                                                                               |
| ------------------ | ------------------------------------------------------------------------------------------------------| 
| `open()`           | Opens a file given a pathname and flags (e.g., read/write). Returns a non-negative FD or -1 on error. |
| `read()`           | Reads bytes from the FD into a buffer. Returns the number of bytes read or -1 on error.               |
| `write()`          | Writes bytes from a buffer to the FD. Returns the number of bytes written or -1 on error.             |
| `close()`          | Closes the FD and releases resources. After closing, FD becomes invalid.                              |
| `dup()` / `dup2()` | Creates a copy of an FD. `dup2()` can duplicate onto a specified FD number.                           |
| `pipe()`           | Creates a unidirectional data channel using two FDs: one for reading, one for writing.                |
| `fcntl()`          | Can change FD flags, file status flags, or perform locking operations on the FD.                      |


Flags in open() are used to define the access mode, file creation rules, and additional settings that determine how the file is opened and accessed. This is done to ensure the file behaves exactly as needed for the specific operation, such as reading, writing, appending, or creating new files safely. These flags are defined in `<fcntl.h>`.

Flags can be combined with bitwise OR (`|`) to specify multiple behaviors. When using `O_CREAT`, a third argument specifying the file permission mode (e.g., `0644`) is required.

| Flag              | Description                                                      | Typical Usage                       |
|-------------------|------------------------------------------------------------------|-------------------------------------|
| `O_RDONLY`        | Open file for read-only access                                   | Read only                           |
| `O_WRONLY`        | Open file for write-only access                                  | Write only                          |
| `O_RDWR`          | Open file for both reading and writing                           | Read and write                      |
| `O_CREAT`         | Create file if it does not exist                                 | Requires a mode argument            |
| `O_EXCL`          | Ensure that `O_CREAT` fails if file exists                       | Used for exclusive file creation    |
| `O_TRUNC`         | Truncate file to zero length if it exists                        | Clear contents when opening         |
| `O_APPEND`        | Append data to the end of the file on each write                 | Writes will always add to file end  |
| `O_NONBLOCK`      | Open file in non-blocking mode                                   | For non-blocking I/O (e.g., pipes)  |
| `O_SYNC`          | Writes are synchronized (blocking until data is written to disk) | Ensure data integrity               |

File permission types are used to define and control the access rights of different users (owner, group, others) to files and directories. This is done to ensure proper security and prevent unauthorized reading, writing, or execution of files in a multi-user environment. These constants are defined in `<sys/stat.h>`.

Permissions are often combined with bitwise OR (`|`) to set multiple permissions. The numeric values are shown in octal notation, commonly used in Unix permission settings.

| Permission Flag     | Description                      | Numeric Value (Octal)| Usage Example        |
|---------------------|----------------------------------|----------------------|----------------------|
| `S_IRUSR`           | Read permission, owner           | 0400                 | Owner can read       |
| `S_IWUSR`           | Write permission, owner          | 0200                 | Owner can write      |
| `S_IXUSR`           | Execute/search permission, owner | 0100                 | Owner can execute    |
| `S_IRGRP`           | Read permission, group           | 0040                 | Group can read       |
| `S_IWGRP`           | Write permission, group          | 0020                 | Group can write      |
| `S_IXGRP`           | Execute/search permission, group | 0010                 | Group can execute    |
| `S_IROTH`           | Read permission, others          | 0004                 | Others can read      |
| `S_IWOTH`           | Write permission, others         | 0002                 | Others can write     |
| `S_IXOTH`           | Execute/search permission, others| 0001                 | Others can execute   |


Example C program using all these functions

```c
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd, fd_dup, pipefd[2];
    char buffer[20];

    // open a file (create if doesn't exist, write only)
    fd = open("example.txt", O_CREAT | O_WRONLY, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // write to file
    if (write(fd, "Hello, world!\n", 14) < 0) {
        perror("write");
        close(fd);
        return 1;
    }

    // duplicate fd to fd_dup
    fd_dup = dup(fd);
    if (fd_dup < 0) {
        perror("dup");
        close(fd);
        return 1;
    }

    // use fcntl to set fd to close-on-exec
    if (fcntl(fd, F_SETFD, FD_CLOEXEC) < 0) {
        perror("fcntl");
    }

    // create a pipe
    if (pipe(pipefd) < 0) {
        perror("pipe");
        close(fd);
        close(fd_dup);
        return 1;
    }

    // write to pipe write end
    if (write(pipefd[1], "pipe test", 9) < 0) {
        perror("write pipe");
    }

    // read from pipe read end
    if (read(pipefd[0], buffer, sizeof(buffer)) < 0) {
        perror("read pipe");
    }

    // close all FDs
    close(fd);
    close(fd_dup);
    close(pipefd[0]);
    close(pipefd[1]);

    return 0;
}
```


### 🌲 Linked Lists

```c
typedef struct s_list
{
    void			*content;
    struct s_list	*next;
}			t_list;
```

---

## 🛠️ Makefile
