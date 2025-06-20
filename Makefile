# ============================================================================ #
#                            MAKEFILE DOCUMENTATION                            #
# ============================================================================ #
# Build system for libft, a custom C library containing reimplementations of
# standard library functions and additional utilities.


# ============================================================================ #
#                                   VARIABLES                                  #
# ============================================================================ #
# NAME - Output library name following Unix convention for static libraries (.a extension)
# CC -Compiler command (cc is typically aliased to the system's default C compiler)
# CFLAGS - Compiler flags enforcing strict compilation:
# 	- Wall: Enable all standard warnings
# 	- Wextra: Enable extra warnings
# 	- Werror: Treat warnings as errors
# SRC_DIR - Directory containing source files
# OBJ_DIR - Directory for object files (separate from sources for cleaner organization)
# SRCS - Core library source files (standard functions)
# BONUS_SRCS - Bonus source files (linked list functions)
# OBJS - Object files derived from SRCS with OBJ_DIR prefix
# BONUS_OBJS - Bonus object files derived from BONUS_SRCS with OBJ_DIR prefix

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./srcs
OBJ_DIR = ./objs

SRCS = ft_bzero.c ft_isascii.c ft_memchr.c ft_memset.c ft_putstr_fd.c ft_striteri.c ft_strlen.c \
		ft_strrchr.c ft_toupper.c ft_calloc.c ft_isdigit.c ft_memcmp.c ft_putchar_fd.c ft_split.c \
		ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_isalnum.c ft_isprint.c ft_memcpy.c ft_putendl_fd.c \
		ft_strchr.c ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c ft_itoa.c ft_memmove.c \
		ft_putnbr_fd.c ft_strdup.c ft_strlcpy.c ft_strnstr.c ft_tolower.c

BONUS_SRCS = ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstnew_bonus.c \
				ft_lstsize_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c 

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
BONUS_OBJS = $(addprefix $(OBJ_DIR)/, $(BONUS_SRCS:.c=.o))

# ============================================================================ #
#                               BUILD TARGETS                                  #
# ============================================================================ #
# [TARGET] all - Default target (builds the core library)
# [TARGET] $(OBJ_DIR) - Creates the object directory if it doesn't exist
# [RULE] %.o -Compilation rule for .c to .o files:
# 	- Compiles with strict flags
# 	- Places objects in OBJ_DIR
# [TARGET] $(NAME) - Builds the static library using ar (archive tool):
# 	- r: Replace existing files in archive
# 	- c: Create archive if it doesn't exist
# 	- s: Write an object-file index (equivalent to ranlib)
# 	Rationale for static library (.a):
# 		- Standard format for distributing reusable C functions
# 		- Can be linked against multiple programs
# 		- Faster execution than dynamic linking for small libraries
# [TARGET] bonus - Builds both core and bonus components into the library
# [TARGET] clean - Removes all object files (keeps library)
# [TARGET] fclean - Full clean (removes objects and library)
# [TARGET] re - Rebuilds everything from scratch
# [PHONY TARGET] PHONY - Declares targets that aren't actual files

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@


$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)


bonus: $(OBJS) $(BONUS_OBJS)
	@ar rcs $(NAME) $(BONUS_OBJS)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus