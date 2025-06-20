/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:01:06 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/20 20:44:37 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Compares up to `n` characters of two strings `s1` and `s2`.
 * 
 * @headerfile <string.h>
 *
 * @param s1
 * The first null-terminated string to compare.
 *
 * @param s2
 * The second null-terminated string to compare.
 *
 * @param n
 * The maximum number of characters to compare.
 *
 * @return int
 * The difference between the first differing characters as unsigned char values, or `0` if equal up to `n`.
 *
 * @note behavior
 * If either pointer is `NULL`, the behavior is undefined.
 *
 * @details
 * 1. Iterate through both strings while `n` is not exhausted.
 * 2. Stop when characters differ or either string ends.
 * 3. Return the difference or 0 if all characters matched.
 */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = -1;
	if (!(s1 || s2))
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	while (++i < n && (s1[i] != '\0' || s2[i] != '\0'))
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
