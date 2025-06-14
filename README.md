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

### 🔢 Integers
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

### 🆎 Characters
```c
char            c;  // 1 byte (8 bites): Range -128 to 127 or 0 to 255
unsigned char   c;  // 1 byte (8 bites): Range 0 to 255
```

### 🧠 Pointers and Memory
```c
void    *v;
int     *i;
char    *s;
```

### 📤 File Descriptors


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
