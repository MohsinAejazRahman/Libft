# 📚 libft - Custom C Library
`libft` is the first project in the 42 core curriculum. It requires you to reimplement standard C library functions from `<ctype.h>`, `<stdlib.h>`, `<string.h>` and `<unistd.h>` along with some custom funcrtions. Here you must organize these functions into a reusable static library. This `README` will help you **understand the theory and mechanisms of C** to help you write these functions which have been grouped by category.

> 🔍 **Note:**  
This document is **not a tutorial** and does **not explain how to implement code** for each function. Instead, it provides a overview and theory to help you understand the core features of the C language. To write your own implementation, refer to the documentation within each individual `.c` file in the `srcs/` directory. There you will find documentation on the specific function.

Although this isn't a tutorial, I've written this `README` specifically with **libft** in mind. I've made an effort to stay within the scope of what's required for the project, so that the explanations remain relevant and concise. If you're looking for deeper understanding or broader C concepts, feel free to explore my other projects where I cover topics in more detail.

<br> 

---
# 📑 Table of Contents

- [Project Structure](#-project-structure)
- [Integers](#0️⃣-integers)
- [Floating-Point Numbers](#1️⃣-floating-point-numbers)
- [Characters](#-characters)
- [Pointers](#-pointers)
- [Structs](#-structs)
- [File Descriptors](#-file-descriptors)
- [Header Files](#-header-files)
- [Makefile](#️-makefile)
- [Additional Resources](#-additional-resources)

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
# 0️⃣ Integers

Integers are whole numbers (positive, negative, and zero) stored in memory as binary numbers. The C language provides several integer types to optimize memory usage and performance. Each type has a fixed size, which determines its range of possible values. 

This is because:

- `Memory Efficiency`: Smaller integers (like `short`) use less memory.
- `Performance`: Some processors handle certain sizes faster.
- `Range Control`: Ensures numbers fit within expected limits.
- `Hardware Compatibility`: Matches CPU architecture (e.g., 32-bit vs. 64-bit).

## 🔢 Integer Representation

Integers can be either signed or unsigned and have different value ranges. Signed integers use the most significant bit (MSB - the leftmost bit) as a sign flag, where 1 indicates a negative number and 0 indicates positive. This representation means signed integers have a range of ±2^(n-1), where n is the number of bits. In contrast, unsigned integers dedicate all bits to representing magnitude, giving them a range of 0 to +2^n.

| Property          | Signed Integers                     | Unsigned Integers                   |
|-------------------|-------------------------------------|-------------------------------------|
| Representation    | Negative and positive numbers       | Only non-negative numbers (≥ 0)     |
| Storage Method    | Two's complement                   | Pure binary                         |
| Use Case          | General arithmetic                 | Bit manipulation, counters          |

## 📏 Standard Integer Types

```c
short               s;      // 2 bytes (16 bits): Range -32,768 to 32,767
unsigned short      us;     // 2 bytes (16 bits): Range 0 to 65,535
int                 i;      // 4 bytes (32 bits): Range -2,147,483,648 to 2,147,483,647
unsigned int        ui;     // 4 bytes (32 bits): Range 0 to 4,294,967,295
long                l;      // 8 bytes (64 bits): Range -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
unsigned long       ul;     // 8 bytes (64 bits): Range 0 to 18,446,744,073,709,551,615
unsigned long int   uli;    // 8 bytes (64 bits): Range 0 to 18,446,744,073,709,551,615
unsigned long long  ull;    // 8 bytes (64 bits): Range 0 to 18,446,744,073,709,551,615
```
## 📐 Fixed-Width Integers (C99)
Data types like `int` and `long` had sizes that varied across compilers and architectures (e.g., 16-bit `int` on older systems vs. 32-bit on modern ones), leading to unpredictable behavior in cross-platform code. To fix this, fixed-width integers (e.g., `int32_t`, `uint64_t`) were introduced in `<stdint.h>`.

Fixed-width types guarantee exact bit widths (e.g., 8, 16, 32, or 64 bits), ensuring consistent behavior regardless of hardware or OS. They are essential for:

- **Precision-critical applications** (e.g., cryptography, binary file formats) where exact bit sizes are mandatory
- **Embedded systems** where memory layout must match hardware registers or protocols (e.g., network packets)
- **Avoiding undefined behavior** in bit manipulation or overflow scenarios

```c
int8_t          i8;     // 1 byte (8 bits): Range -128 to 127
uint8_t         u8;     // 1 byte (8 bits): Range 0 to 255
int16_t         i16;    // 2 bytes (16 bits): Range -32,768 to 32,767
uint16_t        u16;    // 2 bytes (16 bits): Range 0 to 65,535
int32_t         i32;    // 4 bytes (32 bits): Range -2,147,483,648 to 2,147,483,647
uint32_t        u32;    // 4 bytes (32 bits): Range 0 to 4,294,967,295
int64_t         i64;    // 8 bytes (64 bits): Range -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
uint64_t        u64;    // 8 bytes (64 bits): Range 0 to 18,446,744,073,709,551,615
```
<br>

---
# 1️⃣ Floating-Point Numbers

Floating-point numbers represent real numbers (fractions) in C. They're stored using a special binary format that balances range and precision. C provides two primary floating-point types: `float` and `double`, with `double` offering greater precision at the cost of more memory. This allows for:

- **Precision Control**: Different applications need different levels of precision  
- **Memory Efficiency**: `float` uses less memory than `double`  
- **Performance**: Some processors handle `float` operations faster  
- **Scientific Computing**: Essential for math, physics, and engineering calculations  

## 🔣 Floating-Point Representation

Floating-point numbers use IEEE 754 standard representation with three components:

1. **Sign bit**: Determines positive/negative (1 bit)
2. **Exponent**: Scales the number (8 bits for `float`, 11 bits for `double`)
3. **Mantissa**: The significant digits (23 bits for `float`, 52 bits for `double`)

This representation allows for:
- Very large numbers (limited by exponent)
- Fractional precision (limited by mantissa)
- Special values like infinity and NaN (Not a Number)

| Property          | float (32-bit)                  | double (64-bit)                  |
|-------------------|---------------------------------|----------------------------------|
| Size              | 4 bytes                         | 8 bytes                          |
| Precision         | ~7 decimal digits               | ~15 decimal digits               |
| Range             | ±1.2×10⁻³⁸ to ±3.4×10³⁸         | ±2.2×10⁻³⁰⁸ to ±1.8×10³⁰⁸        |
| Use Case          | Graphics, embedded systems      | Scientific computing, finance    |

```c
float  f;  // 4 bytes: Range ±1.2×10⁻³⁸ to ±3.4×10³⁸, ~7 digit precision
double d;  // 8 bytes: Range ±2.2×10⁻³⁰⁸ to ±1.8×10³⁰⁸, ~15 digit precision
```

<br>

---
# 🆎 Characters
Characters in C are single alphabetic, numeric, or symbolic values stored using the `char` data type. `char` is actually an integer type that stores ASCII values (or extended character codes) in 1 byte (8 bits) of memory. Because of this you might wonder why do character types exist

- **Text Representation**: Fundamental for handling strings and text data
- **Memory Efficiency**: Smallest addressable unit of memory (1 byte)
- **Hardware Compatibility**: Matches processor's byte-oriented operations
- **Flexibility**: Can be used as both characters and small integers

## 🔤 Character Representation

Characters are stored as their ASCII (or Unicode) numeric values:

| Property          | Description                          |
|-------------------|--------------------------------------|
| Storage Size      | 1 byte (8 bits)                      |
| Default           | Implementation-defined (usually signed) |

```c
char            c;  // 1 byte (8 bites): Range -128 to 127 or 0 to 255
unsigned char   c;  // 1 byte (8 bites): Range 0 to 255
```

## 🅰️ ASCII Table (0-127)

**Control Characters (0-31, 127):**
  - Non-printable characters for device control
  - Example: `0x07` (BEL) makes an alert sound

**Printable Characters (32-126):**
  - Includes letters, numbers, punctuation
  - `0x20` is space character
  - `0x30-0x39`: Digits 0-9
  - `0x41-0x5A`: Uppercase A-Z
  - `0x61-0x7A`: Lowercase a-z

**Extended ASCII (128-255):**
  - Not part of standard ASCII
  - Varies by character encoding (ISO-8859-1, Windows-1252, etc.)

| Dec | Hex | Char       | Dec | Hex | Char       | Dec | Hex | Char       | Dec | Hex | Char       | Dec | Hex | Char       |
|-----|-----|------------|-----|-----|------------|-----|-----|------------|-----|-----|------------|-----|-----|------------|
| 0   |0x00 |`NUL` (null)| 26 |0x1A |`SUB`      | 52 |0x34 |`4`        | 78 |0x4E |`N`        |104 |0x68 |`h`        |
| 1   |0x01 |`SOH`      | 27 |0x1B |`ESC`      | 53 |0x35 |`5`        | 79 |0x4F |`O`        |105 |0x69 |`i`        |
| 2   |0x02 |`STX`      | 28 |0x1C |`FS`       | 54 |0x36 |`6`        | 80 |0x50 |`P`        |106 |0x6A |`j`        |
| 3   |0x03 |`ETX`      | 29 |0x1D |`GS`       | 55 |0x37 |`7`        | 81 |0x51 |`Q`        |107 |0x6B |`k`        |
| 4   |0x04 |`EOT`      | 30 |0x1E |`RS`       | 56 |0x38 |`8`        | 82 |0x52 |`R`        |108 |0x6C |`l`        |
| 5   |0x05 |`ENQ`      | 31 |0x1F |`US`       | 57 |0x39 |`9`        | 83 |0x53 |`S`        |109 |0x6D |`m`        |
| 6   |0x06 |`ACK`      | 32 |0x20 |` ` | 58 |0x3A |`:`        | 84 |0x54 |`T`        |110 |0x6E |`n`        |
| 7   |0x07 |`BEL` |33 |0x21 |`!`       | 59 |0x3B |`;`        | 85 |0x55 |`U`        |111 |0x6F |`o`        |
| 8   |0x08 |`BS` |34|0x22|`"`      | 60 |0x3C |`<`        | 86 |0x56 |`V`        |112 |0x70 |`p`        |
| 9   |0x09 |`TAB`      | 35 |0x23 |`#`       | 61 |0x3D |`=`        | 87 |0x57 |`W`        |113 |0x71 |`q`        |
|10   |0x0A |`LF` |36|0x24|`$`      | 62 |0x3E |`>`        | 88 |0x58 |`X`        |114 |0x72 |`r`        |
|11   |0x0B |`VT` |37|0x25|`%`   | 63 |0x3F |`?`        | 89 |0x59 |`Y`        |115 |0x73 |`s`        |
|12   |0x0C |`FF` |38|0x26|`&`     | 64 |0x40 |`@`        | 90 |0x5A |`Z`        |116 |0x74 |`t`        |
|13   |0x0D |`CR` |39|0x27|`'`   | 65 |0x41 |`A`        | 91 |0x5B |`[`        |117 |0x75 |`u`        |
|14   |0x0E |`SO`       | 40 |0x28 |`(`       | 66 |0x42 |`B`        | 92 |0x5C |`\`        |118 |0x76 |`v`        |
|15   |0x0F |`SI`       | 41 |0x29 |`)`       | 67 |0x43 |`C`        | 93 |0x5D |`]`        |119 |0x77 |`w`        |
|16   |0x10 |`DLE`      | 42 |0x2A |`*`       | 68 |0x44 |`D`        | 94 |0x5E |`^`        |120 |0x78 |`x`        |
|17   |0x11 |`DC1`      | 43 |0x2B |`+`       | 69 |0x45 |`E`        | 95 |0x5F |`_`        |121 |0x79 |`y`        |
|18   |0x12 |`DC2`      | 44 |0x2C |`,`       | 70 |0x46 |`F`        | 96 |0x60 |`` ` ``    |122 |0x7A |`z`        |
|19   |0x13 |`DC3`      | 45 |0x2D |`-`       | 71 |0x47 |`G`        | 97 |0x61 |`a`        |123 |0x7B |`{`        |
|20   |0x14 |`DC4`      | 46 |0x2E |`.`       | 72 |0x48 |`H`        | 98 |0x62 |`b`        |124 |0x7C |`|`        |
|21   |0x15 |`NAK`      | 47 |0x2F |`/`       | 73 |0x49 |`I`        | 99 |0x63 |`c`        |125 |0x7D |`}`        |
|22   |0x16 |`SYN`      | 48 |0x30 |`0`       | 74 |0x4A |`J`        |100 |0x64 |`d`        |126 |0x7E |`~`        |
|23   |0x17 |`ETB`      | 49 |0x31 |`1`       | 75 |0x4B |`K`        |101 |0x65 |`e`        |127 |0x7F |`DEL`      |
|24   |0x18 |`CAN`      | 50 |0x32 |`2`       | 76 |0x4C |`L`        |102 |0x66 |`f`        |
|25   |0x19 |`EM`       | 51 |0x33 |`3`       | 77 |0x4D |`M`        |103 |0x67 |`g`        |

<br>

---
# 🧠 Pointers
Pointers are fundamental to C programming, acting as variables that store memory addresses rather than direct values. 
They enable efficient memory management, data structures, and low-level system access. Pointers provide indirect access 
to data stored elsewhere in memory.

## ⚙️ Basics

A pointer declaration consists of a data type followed by an asterisk. The type indicates what kind of data the pointer 
references, while the asterisk denotes it as a pointer variable:

```c
int   *ptr;   // Pointer to integer (integer array)
char  *cptr;  // Pointer to character (string)
void  *fptr;  // Pointer to undefined data type
```

When working with pointers, two fundamental operators are essential. The address-of operator (&) retrieves the memory location 
of a variable, while the dereference operator (*) accesses the value stored at a pointer's address. The relationship between 
pointers, addresses, and values can be visualized through a simple table:

| Concept      | Symbol | Example       | Description                          |
|--------------|--------|---------------|--------------------------------------|
| Address-of   | &      | `&variable`   | Gets memory location of a variable   |
| Dereference  | *      | `*pointer`    | Accesses value at pointer's address  |
| Pointer Decl | *      | `int *ptr`    | Creates a pointer variable           |

> 🔍 **Note:**  
In C, function parameters follow strict rules:  
<br> **Primitive types and structs** create independent copies in the function's stack frame. Any modifications affect only the 
local copy and are discarded when the function returns.  
<br> **Pointer parameters** receive a copy of the memory address. While the pointer copy itself follows these rules, dereferencing 
it accesses the original memory location. This allows for modifications to the referenced data, but requires explicit management.  
<br> This means that:<br> 1. Memory modifications through dereferenced pointers are perminent beyond function <br>2. Losing the last 
reference to allocated memory creates unrecoverable leaks (security hazzard) <br>3. There is no automatic mechanism to revert 
pointer-based modifications <br>4. All pointer arithmetic must maintain valid address boundaries  

## 🧩 Pointer Types and Void Pointers

C supports pointers to any data type, including the special void pointer (void *) which can point to any data type but requires 
explicit typecasting for dereferencing:

```c
int   num = 10;
void  *vptr = &num;           // Valid
printf("%d", *(int *)vptr);   // Requires typecast
```

The behavior of different pointer types is important to understand:


| Pointer Type | Size (32/64 Bit Architecture) | Arithmetic Behavior        | Dereference Behavior |
|--------------|------|----------------------------|-----------------------|
| int *        | 4/8 bytes  | Moves by sizeof(int) bytes | Reads 4 bytes         |
| char *       | 4/8 bytes | Moves by 1 byte            | Reads 1 byte          |
| void *       | 4/8 bytes | Cannot perform arithmetic  | Cannot dereference    |


## 🧮 Pointer Arithmetic and Arrays

Pointers and arrays are closely related in C. Array names act as constant pointers to the first element, and pointer arithmetic allows efficient array traversal:


```c
int arr[3] = {10, 20, 30};
int *ptr = arr; // Equivalent to &arr[0]
ptr++;          // Now points to arr[1]
```
> 🔍 **Note:**  
Pointer arithmetic modifies the base address stored in the pointer variable such that each increment operation (++) advances the 
pointer by sizeof(type) bytes. After modification, the pointer no longer references the original array head and there is no automatic 
reset mechanism for pointer positions 
<br><br>
Best Practice:
Maintain the original array pointer in a separate variable if continued access to the head element is required. Pointer arithmetic 
should only be used when the loss of the original reference is explicitly intended.

The relationship between arrays and pointers can be summarized as:

| Expression | Equivalent To | Value Produced               |
|------------|---------------|-------------------------------|
| arr[i]     | *(arr + i)    | Value at index i              |
| &arr[i]    | arr + i       | Address of element at index i |
| *arr       | arr[0]        | First element's value         |


## 🧑‍🎓 Pointer Typecasting


Pointer typecasting allows treating memory as different data types, which is particularly useful when working with void pointers or memory allocation:


```c
float f = 3.14;
int *iptr = (int *)&f; // Treat float bits as int
```


Common pointer typecasting scenarios include:


| Use Case                  | Example                          | Notes                              |
|---------------------------|----------------------------------|------------------------------------|
| Void pointer conversion   | `(int *)vptr`                   | Required before dereferencing      |
| Memory reinterpretation   | `(char *)&int_var`              | Examines individual bytes          |
| Struct pointer conversion | `(Child *)parent_ptr`           | Used in inheritance-like patterns  |


## 🔗 Pointers to Pointers


Multiple levels of indirection are possible in C, enabling pointers to pointers. This is particularly useful for dynamic multidimensional arrays and modifying pointer arguments in functions:


```c
int value = 100;
int *ptr = &value;
int **pptr = &ptr; // Pointer to pointer
```


The dereferencing behavior changes with each level:


| Declaration | Type          | Dereference Once | Dereference Twice |
|-------------|---------------|-------------------|--------------------|
| int *       | Pointer       | Value             | Invalid            |
| int **      | Pointer-to-pointer | Pointer        | Value              |


## 🛡️ Const and Pointers


The const qualifier can be applied to pointers in different ways, each providing specific protection:


```c
const int *ptr1;        // Pointer to constant data
int *const ptr2;        // Constant pointer to data
const int *const ptr3;  // Constant pointer to constant data
```


The variations in const placement create different protections:


| Declaration Form          | Pointer Changeable | Data Changeable |
|---------------------------|--------------------|------------------|
| const int *ptr            | Yes                | No               |
| int *const ptr            | No                 | Yes              |
| const int *const ptr      | No                 | No               |


## 🎯 Function Pointers


Pointers can also reference functions, enabling dynamic behavior and callbacks:

```c
int add(int a, int b) { return a + b; }
int (*func_ptr)(int, int) = add;
int result = func_ptr(3, 4); // Calls add(3, 4)
```


Function pointer syntax varies by signature:


| Function Type          | Pointer Declaration                  |
|------------------------|---------------------------------------|
| int func(void)         | int (*ptr)(void)                     |
| float func(int, char)  | float (*ptr)(int, char)              |
| void func(double)      | void (*ptr)(double)                  |


<br>

---
# 🧱 Structs
Structs in C are composite data types that allow you to combine variables of different types under a single name. They are fundamental 
for creating complex data structures and organizing related data. A struct declaration defines a new type that groups multiple 
variables (called members):

```c
struct student {
    char  name[50];
    int   age;
    float gpa;
};
```

To use a struct, you declare variables of its type:

```c
int main()
{
    struct student s1;  // Declaration

    s1.age = 20;        // Member access
    return (0);
}
```

Typically typedef is used to avoid writing struct repeatedly:

```c
typedef struct student {
    char name[50];
    int age;
    float gpa;
} Student;

int main () 
{
    Student s1;  // Cleaner declaration

    return (0);
}  
```

## 🧮 Memory Layout
The `student` struct members are stored sequentially in memory with proper alignment:

| Member | Type      | Offset (bytes) | Size (bytes) |
|--------|-----------|----------------|--------------|
| name   | char[50]  | 0              | 50           |
| age    | int       | 52             | 4            |
| gpa    | float     | 56             | 4            |

**Key Observations:**
1. **Padding**: The compiler inserts 2 padding bytes after `name` to align `age` on a 4-byte boundary (common for 32-bit systems)
2. **Total Size**: `sizeof(struct student)` would typically be 60 bytes (50 + 2 padding + 4 + 4)
3. **Alignment**: Members are aligned according to their natural boundaries (chars on 1-byte, ints/floats on 4-byte)

<br>

> 🔍 **Architecture Note:**  
> On 64-bit systems, you might see different padding behavior due to:
> - Larger pointer sizes (8 bytes)
> - Stricter alignment requirements
> - Structure padding optimization (`#pragma pack` can modify this)

**Practical Implications:**
```c
struct student s;
printf("name @ %p\n", &s.name);  // Lowest address
printf("age @ %p\n", &s.age);    // Typically 52 bytes higher
printf("gpa @ %p\n", &s.gpa);    // Typically 56 bytes higher
```

**Memory Visualization:**<br>
┌───────────────────┬──┬───────┬───────┐<br>
 │                name (50 bytes)                              │    P   │            age          │            gpa          │<br>
└───────────────────┴──┴───────┴───────┘

This layout ensures optimal memory access at the cost of some wasted space in padding. The exact offsets may vary between compilers 
and architectures unless packed structures are used.

## 🧩 Data Structures

### 🔗 Linked Lists

The linked list is a fundamental linear data structure where elements are stored in nodes containing both data and a pointer 
to the next node. This structure provides dynamic memory allocation and efficient insertions/deletions compared to arrays. 
In this linked list, the head refers to the first node, while the tail refers to the last (nth) node in the sequence.

**Key Operations:**
- `Insertion`: O(1) at head, O(n) at tail
- `Deletion`: O(1) at head, O(n) elsewhere
- `Traversal`: O(n)

Linked lists excel in scenarios requiring frequent insertions and deletions, as these operations can be performed in constant 
time O(1) at the head. However, they have O(n) access time for arbitrary positions and require additional memory for pointers.

The most basic form is the singly-linked list shown in the template:

```c
typedef struct s_list {
    void *content;          // Pointer to data
    size_t content_size;    // Size of data
    struct s_list *next;    // Pointer to next node
} t_list;
```

### 🗃️ Stacks (LIFO)
Stacks follow the Last-In-First-Out principle, where elements are added and removed from the same end (called the "top"). 
This structure is ubiquitous in computer science for function call management, expression evaluation, and undo mechanisms. 

**Key stack operations** follow strict LIFO discipline:
- `push`: Adds an element to the top
- `pop`: Removes and returns the top element
- `peek`: Returns the top element without removal

A stack can be implemented using either arrays or linked lists:

```c
#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];     // Fixed-size array storage
    int top;                // Index of top element (-1 when empty)
} ArrayStack;

typedef struct s_stack {
    void *content;          // Data element
    struct s_stack *next;   // Next node in stack
} LinkedStack;
```

### 🚦 Queues (FIFO)
Queues implement First-In-First-Out behavior, making them ideal for task scheduling, buffering, and breadth first search algorithms. 

**Key queue operations** maintain FIFO ordering:
- `enqueue`: Adds to the rear
- `dequeue`: Removes from the front
- `peek`: Examines the front element

Like stacks, queues admit both array and linked implementations:

```c
typedef struct {
    int front, rear, size; 
    unsigned capacity;
    int *array;
} ArrayQueue;

typedef struct s_queue {
    void *content;
    struct s_queue *next;
} LinkedQueue;

typedef struct {
    LinkedQueue *front;
    LinkedQueue *rear;
} QueueHead;
```

### 🗃️ Hash Maps
Hash maps provide key-value storage with average O(1) access time through hash function computation. 

**Proper hash map implementation requires consideration of:**
- Hash function `quality and distribution`
- `Collision resolution strategy` (chaining shown here)
- `Load factor management` and `dynamic resizing`
- A basic `chaining implementation` uses an array of linked lists:

```c
typedef struct s_hashnode {
    char *key;
    void *value;
    struct s_hashnode *next;
} HashNode;

typedef struct {
    HashNode **buckets;
    size_t size;
    size_t capacity;
} HashMap;
```

### 🌳 Binary Trees
Binary trees are hierarchical structures where each node has at most two children (left and right). 

**Tree variants specialize for different needs:**
- `Binary Search Trees`: Maintain ordering invariants
- `AVL/Red-Black Trees`: Self-balancing variants
- `Heaps`: Priority queue implementations

They enable efficient searching (O(log n) in balanced trees) and form the basis for more advanced structures:

```c
typedef struct s_btree {
    void *item;
    struct s_btree *left;
    struct s_btree *right;
} t_btree;
```



<br>

---
# 📤 File Descriptors

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

## ⚙️ Common File Descriptor Functions

| Function           | Purpose                                                                                               |
| ------------------ | ------------------------------------------------------------------------------------------------------| 
| `open()`           | Opens a file given a pathname and flags (e.g., read/write). Returns a non-negative FD or -1 on error. |
| `read()`           | Reads bytes from the FD into a buffer. Returns the number of bytes read or -1 on error.               |
| `write()`          | Writes bytes from a buffer to the FD. Returns the number of bytes written or -1 on error.             |
| `close()`          | Closes the FD and releases resources. After closing, FD becomes invalid.                              |
| `dup()` / `dup2()` | Creates a copy of an FD. `dup2()` can duplicate onto a specified FD number.                           |
| `pipe()`           | Creates a unidirectional data channel using two FDs: one for reading, one for writing.                |
| `fcntl()`          | Can change FD flags, file status flags, or perform locking operations on the FD.                      |

## 🏷️ Flags for open()

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

## 🔐 File Permission Types

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

<br>

---
# 📚 Header Files

A header file in C is a file with a `.h` extension that contains C declarations and macro definitions to be shared between multiple 
source files. Rather than duplicating common declarations (e.g., function prototypes, macros, structs, constants) across `.c` files, 
these can be placed in a `.h` file and included using the `#include` directive. This promotes modularity, code reuse, and maintainability.

Header files act as interfaces between different parts of a C program. They expose declarations to other files while keeping 
implementation details encapsulated in the corresponding .c files. This separation of interface and implementation is a fundamental 
design pattern in C programming.

Think of a header file like a "table of contents" or contract for a .c file: it tells other parts of the program what functions, 
constants, and types are available without revealing how they are implemented.

## 🧩 Why Header Files Are Important
`Encapsulation`- Header files separate what a module does (the declarations) from how it does it (the implementation in the .c file). 
This makes it easier to reason about and maintain large codebases.

`Avoiding Redundancy`- Instead of duplicating function prototypes or struct definitions across multiple source files, placing them in a single header 
file and using #include ensures consistency and reduces errors.

`Code Sharing Across Files`- Shared interfaces (e.g., math operations, utility functions, data structures) can be declared once and reused in many files.

`Compiler Support` - The compiler needs to know about functions and data types before they are used. Header files provide this information at 
compile-time via inclusion.

## 📥 Including Header Files

```c
#include <stdio.h>    // System header
#include "utils.h"    // User-defined header
```

> 🔍 Note: 
> System headers (like <stdio.h>) are part of the standard library, while user headers (like "utils.h") are custom and project-specific.

## 🛠️ Common Standard Header Files in C

These headers are included by default in standard C environments and are critical when working with low-level system calls, 
memory management, file I/O, and debugging.

| Header         | Purpose / Contents                                                       |
| -------------- | ------------------------------------------------------------------------ |
| `<stdio.h>`    | Standard Input/Output: `printf`, `scanf`, `fgets`, `FILE*`               |
| `<stdlib.h>`   | General utilities: `malloc`, `free`, `exit`, `atoi`, `rand`              |
| `<string.h>`   | String operations: `strlen`, `strcpy`, `strcmp`, `memset`                |
| `<math.h>`     | Mathematical functions: `sin`, `sqrt`, `pow`, `log`                      |
| `<ctype.h>`    | Character classification: `isalpha`, `isdigit`, `toupper`, `tolower`     |
| `<unistd.h>`   | POSIX OS API: `read`, `write`, `fork`, `exec`, `sleep`, `getpid`         |
| `<fcntl.h>`    | File control options: file access flags for `open()` and `fcntl()`       |
| `<sys/stat.h>` | File information: file permission constants and `stat()` function        |
| `<time.h>`     | Time manipulation: `time`, `difftime`, `strftime`, `clock`               |
| `<errno.h>`    | Error reporting: `errno`, predefined error codes like `EACCES`, `ENOENT` |
| `<assert.h>`   | Debugging: `assert()` macro for testing assumptions                      |


## 🧑‍💻 Writing Custom Header Files

When creating your own C modules, you should provide a corresponding header file that contains only the declarations 
of the functions, types, and macros the module provides.

Every header file should be protected with header guards to prevent multiple inclusions, which can cause duplicate definition errors 
during compilation. This is done using preprocessor directives:

```c
#ifndef HEADER_NAME
#define HEADER_NAME

// contents of header file

#endif
```

This ensures that even if a file is included multiple times in different parts of the project, its contents will be processed only once.
The header file alone doesn't generate any code. It's the corresponding .c file that defines the function bodies. During compilation:
- The preprocessor includes the .h file's contents where the #include appears.
- The compiler compiles .c files to .o (object) files.
- The linker links all .o files together using the declarations provided in the headers as references.
If the linker can't find the definitions (i.e., the .c file isn't compiled or linked), it will throw an undefined reference error.

| Guideline                               | Description                                                                 |
| --------------------------------------- | --------------------------------------------------------------------------- |
| One `.h` per `.c`                       | Each source file should have a corresponding header to declare its API      |
| Don’t include `.c` files                | Only include `.h` files to maintain proper separation and build order       |
| Keep headers clean                      | Avoid including unnecessary headers to reduce compile time and dependencies |
| Avoid function definitions in `.h`      | Only use declarations; function *definitions* should stay in `.c` files     |
| Use forward declarations where possible | Declare structs and functions without including full headers unnecessarily  |
| Use header guards                       | Always protect against multiple inclusion with `#ifndef` or `#pragma once`  |


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

```makefile
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

```makefile
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

```makefile
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

```makefile
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

```makefile
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

```makefile
# config.mk (shared across projects)
CC := gcc
CFLAGS := -Wall -O2
```

```makefile
include config.mk  # Import variables

program: main.c
    $(CC) $(CFLAGS) -o program main.c
```

For large projects, dependencies (e.g., .h file inclusions) can be auto-generated by tools like gcc -M and 
stored in .d files. These are dynamically included:

```makefile
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

```makefile
include shared_rules.mk  # Searches ./shared_rules.mk, then -I paths, then system dirs
```



### 💬 Comments
Comments (`#`) document the Makefile's logic for future maintainers. They are ignored by make.

```makefile
# Build the final executable (PHONY to force rebuild)
.PHONY: all
all: $(TARGET)  
```

<br>

---
# 📚 Additional Resources