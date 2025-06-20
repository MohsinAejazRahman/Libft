/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:54:58 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/20 20:38:28 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Fills the first `len` bytes of the memory area pointed to by `b` with the constant byte `c`.
 * 
 * @headerfile <string.h>
 *
 * @param b
 * A pointer to the memory block to fill.
 *
 * @param c
 * The byte value to set, passed as an `int` but used as an `unsigned char`.
 *
 * @param len
 * The number of bytes to set.
 *
 * @return void*
 * Returns the original value of `b`.
 *
 * @note behavior
 * Mimics the behavior of the standard `memset()` function:
 * - Fills memory byte-by-byte with the specified value.
 * - Interprets the value of `c` as an unsigned byte.
 * - If `len == 0`, no memory is modified.
 *
 * @details
 * 1. Store the original address of `b` for return.
 * 2. Cast `b` to `char *` to set memory one byte at a time.
 * 3. Loop through the block, writing `(unsigned char)c` to each byte.
 * 4. Return the original base address.
 */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	void	*result;

	result = b;
	while (len-- > 0)
		*(char *)b++ = c;
	return (result);
}
