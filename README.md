# 📚 Libft - Custom C Library
`libft` is the first project in the 42 core curriculum. It requires you to reimplement standard C library functions from `<ctype.h>`, `<stdlib.h>`, `<string.h>`, and `<unistd.h>`, along with some custom functions. Here, you must organize these functions into a reusable static library. This `README` will help you **understand the theory and mechanisms of C** needed to write these functions, which have been grouped by category.

> 🔍 **Note:**  
> This README provides an overview and theoretical background to help you grasp the core features of the C language relevant to this project. It is **not a tutorial** and does **not explain how to implement each function line-by-line**. For specific function documentation and implementation details, please refer to the comments within each individual `.c` file in the `srcs/` directory.

> ❗ **For a much deeper understanding of the implementation details, memory management strategies, and coding patterns used throughout this project, please consult the full [GUIDE.md](./GUIDE.md).**  

Although this document is focused on the scope of **libft**, if you want to explore broader C programming concepts or more detailed explanations, feel free to check out my other projects.


<br> 

---
# 📑 Table of Contents

* [📚 Libft - Custom C Library](#-libft---custom-c-library)
* [📑 Table of Contents](#-table-of-contents)
* [📁 Project Structure](#-project-structure)
* [📄 About the Project](#-about-the-project)
    * [🧾 Scope and Focus](#-scope-and-focus)
    * [🧪 Compilation and Testing](#-compilation-and-testing)
    * [📁 Project Structure Overview](#-project-structure-overview)
* [🧪 Compiling and Testing](#-compiling-and-testing)
* [📚 Additional Resources](#-additional-resources)

<br> 

--- 
# 📁 Project Structure

    📁 libft/
    ├── GUIDE.md
    ├── Makefile
    ├── README.md
    └── srcs
        ├── Allocation
        │   └── ft_calloc.c         (stdlib.h)      - Allocate and zero-initialize memory
        ├── CharacterCase
        │   ├── ft_tolower.c        (ctype.h)       - Convert character to lowercase
        │   └── ft_toupper.c        (ctype.h)       - Convert character to uppercase
        ├── CharacterChecks
        │   ├── ft_isalnum.c        (ctype.h)       - Check if character is alphanumeric
        │   ├── ft_isalpha.c        (ctype.h)       - Check if character is alphabetic
        │   ├── ft_isascii.c        (ctype.h)       - Check if character is ASCII
        │   ├── ft_isdigit.c        (ctype.h)       - Check if character is a digit
        │   └── ft_isprint.c        (ctype.h)       - Check if character is printable
        ├── Conversions
        │   ├── ft_atoi.c           (stdlib.h)      - Convert string to integer
        │   └── ft_itoa.c           (custom)        - Convert integer to string
        ├── FDFunctions
        │   ├── ft_putchar_fd.c     (unistd.h)      - Write a character to file descriptor
        │   ├── ft_putendl_fd.c     (unistd.h)      - Write string with newline to fd
        │   ├── ft_putnbr_fd.c      (unistd.h)      - Write number to file descriptor
        │   └── ft_putstr_fd.c      (unistd.h)      - Write string to file descriptor
        ├── LinkedList
        │   ├── ft_lstadd_back_bonus.c  (custom)    - Add element at the end of list
        │   ├── ft_lstadd_front_bonus.c (custom)    - Add element at the start of list
        │   ├── ft_lstclear_bonus.c     (custom)    - Clear entire linked list
        │   ├── ft_lstdelone_bonus.c    (custom)    - Delete single list element
        │   ├── ft_lstiter_bonus.c      (custom)    - Iterate function over list elements
        │   ├── ft_lstlast_bonus.c      (custom)    - Get last element of list
        │   ├── ft_lstmap_bonus.c       (custom)    - Map function to list elements
        │   ├── ft_lstnew_bonus.c       (custom)    - Create new linked list element
        │   └── ft_lstsize_bonus.c      (custom)    - Get number of elements in list
        ├── MemoryFunctions
        │   ├── ft_bzero.c          (strings.h)     - Zero out a memory block
        │   ├── ft_memchr.c         (string.h)      - Locate byte in memory block
        │   ├── ft_memcmp.c         (string.h)      - Compare two memory areas
        │   ├── ft_memcpy.c         (string.h)      - Copy memory area
        │   ├── ft_memmove.c        (string.h)      - Copy memory safely (overlap-safe)
        │   └── ft_memset.c         (string.h)      - Fill memory with constant byte
        ├── StringFunctions
        │   ├── ft_split.c          (custom)        - Split string into array by delimiter
        │   ├── ft_strchr.c         (string.h)      - Locate first occurrence of char in string
        │   ├── ft_strdup.c         (string.h)      - Duplicate a string (malloc)
        │   ├── ft_striteri.c       (custom)        - Iterate with index on string chars
        │   ├── ft_strjoin.c        (custom)        - Join two strings into new malloc’d string
        │   ├── ft_strlcat.c        (string.h)      - Concatenate string with size limit
        │   ├── ft_strlcpy.c        (string.h)      - Copy string with size limit
        │   ├── ft_strlen.c         (string.h)      - Calculate string length
        │   ├── ft_strmapi.c        (custom)        - Map function to string chars with index
        │   ├── ft_strncmp.c        (string.h)      - Compare first n chars of strings
        │   ├── ft_strnstr.c        (string.h)      - Locate substring in string (bounded)
        │   ├── ft_strrchr.c        (string.h)      - Locate last occurrence of char
        │   ├── ft_strtrim.c        (custom)        - Trim characters from start/end of string
        │   └── ft_substr.c         (custom)        - Extract substring from string
        └── libft.h                  (custom)        - Header with prototypes and macros

<br>

---

# 📄 About the Project

The `libft` project is the foundational exercise in the 42 core curriculum aimed at reinforcing your understanding of the C programming language by reimplementing a core set of standard library functions. Your goal is to create a fully functional, reusable static library that mimics the behavior of functions from `<ctype.h>`, `<stdlib.h>`, `<string.h>`, and `<unistd.h>`, along with several custom utilities.

This project emphasizes mastering:

- **Memory management:** Allocating, initializing, and freeing memory safely and efficiently.
- **Pointer operations:** Manipulating pointers accurately to handle strings, arrays, and buffers.
- **Modular code organization:** Structuring your code across multiple source files and headers for clarity and reusability.
- **Adhering to coding standards:** Writing clean, norm-compliant code that compiles without warnings or errors.

Your implementations must behave identically to their standard counterparts in edge cases and typical usage, while respecting performance and safety constraints.

## 🧾 Scope and Focus

This document does **not** provide step by step implementation instructions or function-level documentation, which can be found within the comments of each `.c` file in the `srcs/` directory and the `libft.h` header. Instead, it offers a project-level overview to help you understand the key objectives, project organization, and important programming concepts necessary to succeed.

## 🧪 Compilation and Testing

You will compile your library into a static archive (`libft.a`) using the provided `Makefile`. Your code should compile cleanly with flags `-Wall -Wextra -Werror` as required by the 42 Norm.

Thorough testing of each function’s behavior under a variety of inputs and edge cases is essential. Although testing scripts are not provided here, consider writing your own or using external testing frameworks to verify correctness and robustness.

## 📁 Project Structure Overview

Your source code is organized into thematic directories under `srcs/` to separate concerns like allocation, character operations, string manipulation, linked lists, and memory functions. The main header file `libft.h` contains prototypes, macros, and includes needed across your codebase.

By maintaining a clear project structure and properly separating interface (`.h`) and implementation (`.c`), you create a maintainable and extensible codebase suitable for reuse in larger projects.

<br>

---

# 📚 Additional Resources

For detailed, function-specific documentation, please refer to the comments inside each `.c` source file and the `libft.h` header file. These contain important information on function behavior, parameters, return values, and any special considerations needed for correct implementation.

The provided `Makefile` includes all necessary rules and flags to compile your library correctly and efficiently. Reviewing it will help you understand the build process and how to customize compilation if needed.

For a deeper exploration of the concepts, memory management strategies, and coding patterns applied throughout this project, please consult the comprehensive [GUIDE.md](./GUIDE.md). It serves as an extended resource to strengthen your understanding beyond the scope of the README and inline documentation.