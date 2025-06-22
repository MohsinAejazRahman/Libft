/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:10:16 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/22 04:47:20 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Searches for the first occurrence of character `c` in the string `s`.
 * 
 * @headerfile <string.h>
 *
 * @param s
 * A null-terminated string to be scanned.
 *
 * @param c
 * The character to search for. It is passed as an `int` but interpreted as an unsigned char.
 *
 * @return char*
 * A pointer to the first occurrence of `c` in `s`, or `NULL` if not found.
 *
 * @note behavior
 * If `c` is '\0', the function returns a pointer to the null terminator.
 * The search includes the null terminator at the end of the string.
 *
 * @details
 * 1. Iterate through the string until the character matches `c`.
 * 2. If found, return the address of that character in `s`.
 * 3. If `c` is not found and `s` ends, return `NULL`.
 */

#include "../libft.h"

char	*ft_strchr(const char *s, char c)
{
	int	i;

	i = -1;
	while (s[++i] != '\0')
		if (s[i] == c)
			return ((char *)s + i);
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}
