/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:42:01 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/20 20:50:08 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Splits a string into an array of substrings using a specified delimiter character.
 *
 * @headerfile <stdlib.h>
 *
 * @param s
 * A null-terminated C string to be split. It must be a valid memory region.
 * The string is parsed sequentially and split at each occurrence of the delimiter `c`.
 *
 * @param c
 * A character delimiter that defines where to split the input string.
 * Consecutive delimiters are treated as a single separator.
 *
 * @return char**
 * A null-terminated array of strings (char pointers), where each string is a segment of the original string `s`.
 * Returns NULL if memory allocation fails or if `s` is NULL.
 *
 * @note behavior
 * Mimics a standard string split function:
 * - Skips leading and consecutive delimiters.
 * - Allocates memory for each word and for the array of pointers.
 * - Frees previously allocated memory if a malloc fails during processing.
 * - The returned array must be freed using `free()` on each string and then on the array itself.
 *
 * @details
 * 1. Uses a helper function to count the number of substrings (words) separated by `c`.
 * 2. Allocates memory for a pointer array of size (word count + 1), with the last element set to NULL.
 * 3. Iterates through `s`, identifying word boundaries based on the delimiter `c`.
 * 4. For each word, calculates its length, allocates space using `malloc()`, and copies the substring using `ft_strlcpy()`.
 * 5. If memory allocation fails at any point, a cleanup function frees all previously allocated memory and returns NULL.
 * 6. Returns the populated null-terminated array of substrings.
 */

#include "libft.h"

static void	free_split(char	**split, int i)
{
	while (i > -1)
		free(split[i--]);
	free(split);
}

static int	mem_aloc(char **split, int i, int w_len, char const *s)
{
	split[i] = malloc(w_len + 1);
	if (!split[i])
		return (free_split(split, i - 1), 0);
	ft_strlcpy(split[i], (s - w_len), w_len + 1);
	return (1);
}

static int	count_words(const char *s, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (*s)
	{
		if (*s == c)
			flag = 0;
		else if (flag == 0 && *s != c)
		{
			flag = -1;
			count++;
		}
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		w_count;
	int		w_len;

	i = 0;
	w_len = 0;
	w_count = count_words(s, c);
	split = malloc((w_count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (i < w_count)
	{
		if (*s != c && *s)
			w_len++;
		else if (w_len > 0)
		{
			if (!(mem_aloc(split, i, w_len, s)))
				return (NULL);
			w_len = 0;
			i++;
		}
		s++;
	}
	return (split[i] = NULL, split);
}
