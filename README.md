# 📚 libft - Custom C Library
`libft` is the first project in the 42 core curriculum. It requires you to reimplement standard C library functions from `<ctype.h>`, `<stdlib.h>`, `<string.h>` and `<unistd.h>` along with some custom funcrtions. Here you must organize them into a reusable static library. This `README` will help you **understand the theory and mechanisms of C** to help you write these functions which have been grouped by category.

> 🔍 **Note:**  
This document is **not a tutorial** and does **not explain how to implement code** for each function. Instead, it provides a overview and theory to help you understand the core features of the C language. To write your own implementation, refer to the documentation within each individual `.c` file in the `srcs/` directory. There you will find documentation on the specific function.

Although this isn't a tutorial, I've written this `README` specifically with **libft** in mind. I've made an effort to stay within the scope of what's required for the project, so that the explanations remain relevant and concise. If you're looking for deeper understanding or broader C concepts, feel free to explore my other projects where I cover topics in more detail.

<br> 

---
# 📑 Table of Contents

- [Project Structure](#project-structure)
- [Library Functions](#library-functions)
  - [Integers](#integers)
  - [Characters and Strings](#characters-and-strings)
  - [Pointers and Memory](#pointers-and-memory)
  - [File Descriptors](#-file-descriptors)
  - [Linked Lists](#linked-lists)
- [Makefile](#makefile)
  - [Structure](#structure)
  - [Components](#components)
- [Additional Resources](#additional-resources)

<br> 

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


<br>

---
# 🧰 Library Functions

## 🔢 Integers
```c
short               s;      // 2 bytes (16 bits): Range -32,768 to 32,767
unsigned short      us;      // 2 bytes (16 bits): Range 0 to 65,535
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

> ❗ **THE FOLLOWING CONTENT IS OUT OF SCOPE**

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

## 🌲 Linked Lists

```c
typedef struct s_list
{
    void			*content;
    struct s_list	*next;
}			t_list;
```
<br>

---
# 🛠️ Makefile

A Makefile is a special configuration file used by the make build automation tool to compile and build software projects **primarily in C/C++**. It is also usable with any language whose compiler can be run with a shell command. It defines rules and dependencies for building targets from source files. Makefiles are essential in C projects because they:

- `Automate the compilation process`
- `Only recompile what's necessary`
- `Manage dependencies between files`
- `Standardize the build process across different environments`

## 🏗️ Structure
A Makefile generally consists of multiple components that define what is being recompiled.

- A `target` is generally the name of a file that is generated by a program after compilation. 
  - A `Phony target` is a specific rule that represents an action rather than files. When invoked, their commands always execute, regardless of whether a file with the same name exists.
- A `prerequisite` (or dependency) is a file used as input to build the target
- A `command` is a shell action executed by make to (re)build the target. Each command must be indented with a tab character (spaces will cause an error). 
- A `rule` defines how to build a target. Each rule can contain multiple commands and follow the following format:

```
target: prerequisite1 prerequisite2
    command1
    command2
```

## 🛠️ Components

### 🎯 Built-in Target Names

| Special Target | Description |
|---------------|-------------|
| `.PHONY` | Marks targets as always executing, regardless of file existence or timestamps. |
| `.SUFFIXES` | Specifies list of suffixes for old-style suffix rules (largely obsolete). |
| `.DEFAULT` | Commands to execute when no other rules are found for a target. |
| `.PRECIOUS` | Prevents deletion of targets if make is interrupted or if they're intermediate files. |
| `.INTERMEDIATE` | Marks targets as intermediate files (normally deleted after use). |
| `.SECONDARY` | Like `.INTERMEDIATE` but files are never automatically deleted. |
| `.DELETE_ON_ERROR` | Deletes target if its commands fail during execution. |
| `.IGNORE` | Ignores errors for specified targets (deprecated in favor of `-` prefix). |
| `.SILENT` | Suppresses command echoing for targets (deprecated in favor of `@` prefix). |
| `.EXPORT_ALL_VARIABLES` | Exports all variables to sub-make processes. |
| `.NOTPARALLEL` | Forces serial execution even when parallel mode (`-j`) is enabled. |

### 🔡 Variables 
Variables in Makefiles are used to store reusable values such as compiler flags, directories, or command names. 
They make the Makefile more maintainable by allowing you to change a value in one place instead of updating it 
everywhere manually. Variables can be defined using:

- `=` - recursive assignment, evaluated when used 
- `:=` - immediate assignment, evaluated at definition

```
CC := gcc  # Compiler
CFLAGS := -Wall -O2  # Compiler flags
TARGET := myprogram  # Output binary name

$(TARGET): main.c
    $(CC) $(CFLAGS) -o $(TARGET) main.c
```
| Automatic Variable | Description                                                                 | Example Usage                          |
|--------------------|-----------------------------------------------------------------------------|----------------------------------------|
| `$@`               | Name of the **target** being built.                                         | `main.o: main.c`<br>`    gcc -c $< -o $@` |
| `$<`               | **First prerequisite** (input file).                                        | `main.o: main.c`<br>`    gcc -c $< -o $@` |
| `$^`               | **All prerequisites** (space-separated).                                    | `app: main.o utils.o`<br>`    gcc $^ -o $@` |
| `$?`               | Prerequisites **newer than target** (for incremental builds).               | `log: changes.txt`<br>`    echo "Changed: $?" >> log` |
| `$*`               | **Stem** of the target (filename without extension, in pattern rules).      | `%.o: %.c`<br>`    gcc -c $< -o $*.o`    |
| `$+`               | All prerequisites (including duplicates).                                   | `link: a.o b.o a.o`<br>`    gcc $+ -o $@` |
| `$\|`               | **Order-only prerequisites** (ignored for timestamp checks).                | `build/: \| mkdir`<br>`    mkdir $@`     |


### 🃏 Wildcards
Wildcards (`*`, `~` and `%`) allow you to define patterns for matching multiple files, reducing repetitive rules. 
Wildcard characters can be muted (ignored) by using a backslash ("\") before them.

- `%` - used in pattern rules to generalize compilation steps
- `*` - specifies a list of all the files (in the working directory)
- `~` - represents your home directory (/home)

```
%.o: %.c  # Compile all .c files into .o files
    $(CC) -c $< -o $@

$(TARGET): $(wildcard *.o) # Link all .o files into a single executable
    $(CC) $^ -o $@
```

### ƒ Functions

Functions allow you to process text in the Makefile to compute the files to operate on or the commands to use. A 
function consists of a **function** (e.g *subst*) and **arguments** for the function to operate on. The 
result is substituted into the makefile at the point of the call, just as a variable might be substituted. 
A function call resembles a variable reference:

1. `$(function arguments)`
2. `${function arguments}`

Make provides built-in functions:

- `$(wildcard *.c)` - Lists all .c files
- `$(patsubst %.c,%.o,*.c)` - Replaces .c extensions with .o.
- `$(shell command)` - Executes a shell command (e.g., $(shell ls)).

```
SOURCES := $(wildcard src/*.c)  # Finds all .c files in src/
OBJECTS := $(patsubst %.c,%.o,$(SOURCES))  # Converts to .o files

$(TARGET): $(OBJECTS)
    $(CC) $^ -o $@
```

### 🎭 Conditionals

Conditionals allow specific parts of a Makefile to be executed. They compare the value of one variable to another 
or to a constant string. `ifeq`, `ifneq` and `ifdef` enable dynamic behavior based on variables or environments. 

- `ifeq` - Expands all variable references in arg1 and arg2 and compare them. If they are identical then the conditional returns true, otherwise false
  - **Syntax:** ifeq (arg1, arg2) - where *"(,)"* can be replaced with either *''* or *""*
- `ifneq` - Expands all variable references in arg1 and arg2 and compare them. If they are different then the conditional returns true, otherwise false
  - **Syntax:** ifneq (arg1, arg2) - where *"(,)"* can be replaced with either *''* or *""*
- `ifdef` - If the variable has a non-empty value, it returns true, otherwise false
  - **Syntax:** ifdef variable-name

They are often used for debug/release builds or platform-specific settings.

```
DEBUG ?= 1  # Default to debug mode

ifeq ($(DEBUG), 1)
    CFLAGS += -g  # Add debug symbols
else
    CFLAGS += -O3  # Optimize for release
endif
```


### 📜 Include Directives
The include directive allows a Makefile to import content from other files, such as shared variables, rules, 
or auto-generated dependencies. This promotes modularity, reduces redundancy, and simplifies maintenance.
When multiple projects (each with their own Makefiles) need the same variables or rules (e.g., compiler flags, paths), 
these can be centralized in a shared file. 

```
# config.mk (shared across projects)
CC := gcc
CFLAGS := -Wall -O2
```

```
include config.mk  # Import variables

program: main.c
    $(CC) $(CFLAGS) -o program main.c
```

For large projects, dependencies (e.g., .h file inclusions) can be auto-generated by tools like gcc -M and 
stored in .d files. These are dynamically included:

```
# Generate and include dependency files
%.d: %.c
    gcc -MM $< > $@

-include $(SOURCES:.c=.d)  # Silently ignore missing files
```

If the included filename isn’t an absolute path (/path/to/file), make searches in this order:
1. Current directory.
2. Directories specified with -I or --include-dir (e.g., make -I ./include).
3. System directories (in order):
    - prefix/include (e.g., /usr/local/include).
    - /usr/gnu/include.
    - /usr/local/include.
    - /usr/include.

```
include shared_rules.mk  # Searches ./shared_rules.mk, then -I paths, then system dirs
```



### 💬 Comments
Comments (`#`) document the Makefile's logic for future maintainers. They are ignored by make.

```
# Build the final executable (PHONY to force rebuild)
.PHONY: all
all: $(TARGET)  
```

<br>

---
# 📚 Additional Resources