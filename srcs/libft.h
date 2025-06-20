/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:21:55 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/20 22:37:42 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief 
 * Custom C library with reimplementations and extensions of standard functions
 * 
 * @headerfile <libft.h>
 * 
 * @details
 * This library provides:
 * - Reimplementations of standard C library functions
 * - Additional utility functions
 * - Bonus linked list functionality
 */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

/**
 * @struct s_list
 * @brief Node structure for singly-linked list implementation
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

/* ========================== CHARACTER FUNCTIONS ========================== */

/**
 * @defgroup ctype Character Type & Conversion
 * @brief Functions for character classification and case conversion
 * 
 * @details
 * - Follow <ctype.h> standard behavior
 * - Accept int argument (EOF-safe)
 * - Return int (0 for false, non-zero for true)
 */
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

/* ========================== STRING FUNCTIONS ========================== */

/**
 * @defgroup string String Manipulation
 * @brief Functions for string and memory operations
 * 
 * @details
 * - Follow <string.h> standard behavior where applicable
 * - Handle NULL inputs according to standard
 * - Memory functions operate on raw bytes
 */
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strchr(const char *s, char c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/* ========================== MEMORY FUNCTIONS ========================== */

/**
 * @defgroup memory Memory Management
 * @brief Functions for dynamic memory allocation
 */
void	*ft_calloc(size_t nitems, size_t size);

/* ========================== CONVERSION FUNCTIONS ========================== */

/**
 * @defgroup conversion Type Conversion
 * @brief Functions for converting between data types
 */
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

/* ========================== OUTPUT FUNCTIONS ========================== */

/**
 * @defgroup output File Descriptor Output
 * @brief Functions for writing to file descriptors
 */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* ========================== STRING UTILITIES ========================== */

/**
 * @defgroup strutil String Utilities
 * @brief Additional string manipulation functions
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/* ========================== LINKED LIST (BONUS) ========================== */

/**
 * @defgroup list Linked List
 * @brief Singly-linked list implementation
 */
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif