# ============================================================================ #
#                            MAKEFILE DOCUMENTATION                            #
# ============================================================================ #
# Build system for libft, a custom C library containing reimplementations of
# standard library functions and additional utilities.

# ============================================================================ #
#                                   COLORS                                     #
# ============================================================================ #
GREEN := \033[32;1m
RESET := \033[0m
ORANGE := \033[38;5;214m

# ============================================================================ #
#                                   VARIABLES                                  #
# ============================================================================ #
# NAME - Output library name following Unix convention for static libraries (.a extension)
# CC - Compiler command (cc is typically aliased to the system's default C compiler)
# CFLAGS - Compiler flags enforcing strict compilation:
#   - Wall: Enable all standard warnings
#   - Wextra: Enable extra warnings
#   - Werror: Treat warnings as errors
# RM - Command to remove files forcefully
# SRC_DIR - Root directory containing all source files
# OBJ_DIR - Directory for object files (separate from sources for cleaner organization)
# SRCS - All core library source files found recursively in SRC_DIR
# BONUS_SRCS - All bonus source files (linked list functions) found recursively
# OBJS - Object files derived from SRCS with OBJ_DIR prefix
# BONUS_OBJS - Bonus object files derived from BONUS_SRCS with OBJ_DIR prefix

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_DIR = srcs
OBJ_DIR = objs
BONUS_DIR = $(SRC_DIR)/LinkedList

SRCS := $(shell find $(SRC_DIR) -type f -name '*.c' ! -path '$(BONUS_DIR)/*')
BONUS_SRCS := $(shell find $(BONUS_DIR) -type f -name '*.c')

OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
BONUS_OBJS := $(patsubst $(BONUS_DIR)/%.c, $(OBJ_DIR)/%.o, $(BONUS_SRCS))

# ============================================================================ #
#                               BUILD TARGETS                                  #
# ============================================================================ #
# all - Default target (builds the core library)
# $(OBJ_DIR) - Creates the object directory structure
# $(NAME) - Builds the static library using ar (archive tool):
#   - r: Replace existing files in archive
#   - c: Create archive if it doesn't exist
#   - s: Write an object-file index (equivalent to ranlib)
# bonus - Builds both core and bonus components into the library
# clean - Removes all object files (keeps library)
# fclean - Full clean (removes objects and library)
# re - Rebuilds everything from scratch

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(GREEN)Compiling: $(RESET)$(notdir $<)...\n"

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(ORANGE)Compiling bonus: $(RESET)$(notdir $<)...\n"

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@printf "$(GREEN)Library $(NAME) created$(RESET)\n"

bonus: $(OBJS) $(BONUS_OBJS)
	@ar rcs $(NAME) $(BONUS_OBJS)
	@printf "$(ORANGE)Bonus functions added to $(NAME)$(RESET)\n"

clean:
	@$(RM) -r $(OBJ_DIR)
	@printf "$(ORANGE)Object files removed$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(ORANGE)Library $(NAME) removed$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re bonus