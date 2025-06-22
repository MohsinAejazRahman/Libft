/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:43:28 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/22 04:47:20 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Finds the last occurrence of character `c` in string `s`.
 * 
 * @headerfile <string.h>
 *
 * @param s
 * A null-terminated string to search.
 *
 * @param c
 * The character to locate, passed as an `int`.
 *
 * @return char*
 * A pointer to the last occurrence of `c`, or `NULL` if not found.
 *
 * @note behavior
 * If `c` is '\0', a pointer to the null terminator is returned.
 *
 * @details
 * 1. Start from the end of the string and move backward.
 * 2. Compare each character to `c`.
 * 3. Return the pointer when a match is found.
 */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s) + 1;
	while (--i > -1)
		if (s[i] == (char)c)
			return ((char *)s + i);
	return (NULL);
}
