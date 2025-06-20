/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:26:44 by mohrahma          #+#    #+#             */
/*   Updated: 2023/12/06 00:26:44 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Allocates and returns a copy of the string `s1`, trimmed of any characters
 * that appear in the string `set` from both the beginning and the end.
 * 
 * @headerfile <stdlib.h>
 *
 * @param s1
 * A null-terminated C string to be trimmed. It may contain leading and trailing
 * characters that match any in the `set`.
 *
 * @param set
 * A null-terminated C string containing the set of characters to trim from `s1`.
 * If `set` is empty, the original `s1` is duplicated.
 *
 * @return char*
 * A newly allocated null-terminated string with the leading and trailing characters
 * from `set` removed from `s1`. If no trimming is needed, a full duplicate of `s1` is returned.
 * If memory allocation fails, `NULL` is returned.
 *
 * @note behavior
 * Mimics the behavior of trimming utilities:
 * - Skips characters from the beginning of `s1` that are in `set` using `start_trim()`.
 * - Skips characters from the end of `s1` that are in `set` using `end_trim()`.
 * - Allocates memory for the new string and copies the trimmed substring using `malloc()` and `ft_strlcpy()`.
 * - If `s1` is entirely made up of characters in `set`, returns an empty string using `ft_strdup("")`.
 *
 * @details
 * 1. Handle edge cases where `s1` is empty by returning a duplicate empty string.
 * 2. Handle edge cases where `set` is empty by returning a full duplicate of `s1`.
 * 3. Use `start_trim()` to calculate the index of the first non-trimmable character.
 * 4. Use `end_trim()` to calculate the index after the last non-trimmable character.
 * 5. If the start index is greater than or equal to the end index, the string is fully trimmed—return an empty string.
 * 6. Allocate enough memory to hold the trimmed result and a null terminator.
 * 7. Use `ft_strlcpy()` to copy the trimmed portion into the new memory block.
 * 8. Return the newly allocated trimmed string.
 */

#include "libft.h"

static int	start_trim(char const *s1, char const *set)
{
	unsigned int	i;
	int				j;

	i = -1;
	while (++i < ft_strlen(s1))
	{
		j = -1;
		while (set[++j] != '\0')
			if (s1[i] == set[j])
				break ;
		if (set[j] == '\0')
			return (i);
	}
	return (i);
}

static int	end_trim(char const *s1, char const *set)
{
	unsigned int	i;
	int				j;
	int				t_len;

	t_len = ft_strlen(s1);
	i = -1;
	while (++i < ft_strlen(s1))
	{
		j = -1;
		while (set[++j] != '\0')
			if (s1[t_len - i - 1] == set[j])
				break ;
		if (set[j] == '\0')
			return (t_len - i);
	}
	return (t_len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*result;

	if (!(*s1))
		return (ft_strdup(""));
	if (!(*set))
		return (ft_strdup((char *)s1));
	start = start_trim(s1, set);
	end = end_trim(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	result = malloc(sizeof(char) * (end - start + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1 + start, end - start + 1);
	return (result);
}
