/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:12:20 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/22 04:47:20 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Compares the first `n` bytes of the memory areas `s1` and `s2`.
 * 
 * @headerfile <string.h>
 *
 * @param s1
 * A pointer to the first memory block to compare.
 *
 * @param s2
 * A pointer to the second memory block to compare.
 *
 * @param n
 * The number of bytes to compare.
 *
 * @return int
 * Returns `0` if the first `n` bytes are equal. Otherwise, returns the difference between the first pair of bytes that differ, interpreted as `unsigned char`.
 *
 * @note behavior
 * Mimics the behavior of the standard `memcmp()` function:
 * - Performs a byte-by-byte comparison.
 * - Does not account for null-termination; works on raw memory.
 * - Stops comparing after the first mismatch or when `n` reaches zero.
 *
 * @details
 * 1. Cast both `s1` and `s2` to `char *` for byte-wise comparison.
 * 2. Iterate over the first `n` bytes of both memory regions.
 * 3. Return the difference between the first non-matching bytes.
 * 4. Return `0` if all `n` bytes match.
 */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n-- > 0)
	{
		if (*(char *)s1 != *(char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (0);
}
