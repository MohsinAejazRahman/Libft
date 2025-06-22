/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:23:27 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/22 04:47:20 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Searches for the first occurrence of substring `s2` in `s1`, limited to the first `n` characters.
 * 
 * @headerfile <string.h>
 *
 * @param s1
 * The null-terminated string to search within.
 *
 * @param s2
 * The null-terminated substring to find.
 *
 * @param n
 * The maximum number of characters to examine in `s1`.
 *
 * @return char*
 * A pointer to the start of the located substring, or `NULL` if not found.
 *
 * @note behavior
 * If `s2` is an empty string, `s1` is returned. If not found within `n`, returns `NULL`.
 *
 * @details
 * 1. Check if `s2` is empty; return `s1` immediately if true.
 * 2. Loop through `s1` within the bounds of `n`.
 * 3. Check for a match by comparing characters from `s1` and `s2`.
 * 4. Return pointer if found, or `NULL` if exhausted.
 */

#include "../libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	s2_len;

	if (!(*s2))
		return ((char *)s1);
	s2_len = 0;
	while (s2[s2_len] != '\0')
		s2_len++;
	i = -1;
	while (s1[++i] != '\0' && i < n)
	{
		j = 0;
		while (s1[i + j] == s2[j] && (i + j) < n && s2[j] != '\0')
			j++;
		if (j == s2_len)
			return ((char *)s1 + i);
	}
	return (NULL);
}
