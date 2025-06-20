/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:02:41 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/20 20:37:04 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Scans the initial `n` bytes of the memory area pointed to by `s` for the first occurrence of the byte `c`.
 * 
 * @headerfile <string.h>
 *
 * @param s
 * A pointer to the memory block to be searched. The data is interpreted as unsigned bytes.
 *
 * @param c
 * The byte value to search for, passed as an `int` but interpreted as an `unsigned char`.
 *
 * @param n
 * The maximum number of bytes to examine starting from `s`.
 *
 * @return void*
 * A pointer to the matching byte within the memory block if found, or `NULL` if `c` does not occur in the first `n` bytes.
 *
 * @note behavior
 * Mimics the behavior of the standard `memchr()` function:
 * - Does not validate the pointer `s`—passing `NULL` with `n > 0` leads to undefined behavior.
 * - If `c` is not found, `NULL` is returned.
 * - Comparison stops at the first match or after `n` bytes, whichever comes first.
 *
 * @details
 * 1. Cast the input pointer `s` to `char *` for byte-level access.
 * 2. Iterate through the memory, comparing each byte to `(unsigned char)c`.
 * 3. If a match is found, return a pointer to the current byte.
 * 4. If no match is found within `n` bytes, return `NULL`.
 */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n-- > 0)
	{
		if (*(char *)s == (char)c)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
