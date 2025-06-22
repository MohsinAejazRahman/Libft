/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:42:26 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/22 04:47:20 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Sets the first `n` bytes of the block of memory pointed to by `s` to zero (null bytes).
 * 
 * @headerfile <strings.h>
 *
 * @param s
 * A pointer to the start of the memory block to be zeroed. The memory must be mutable and large enough to hold `n` bytes.
 *
 * @param n
 * The number of bytes to set to `0`. If `n` is `0`, the function does nothing.
 *
 * @return void
 * This function does not return a value. It directly modifies the memory pointed to by `s`.
 *
 * @note behavior
 * Mimics the behavior of the standard `bzero()` function:
 * - Does not perform any boundary or validity checks on the pointer `s`.
 * - Passing a null pointer with `n > 0` results in undefined behavior.
 * - Overlapping memory regions are not handled specially.
 *
 * @details
 * 1. Cast the void pointer `s` to a `char *` so memory can be set byte-by-byte.
 * 2. Loop from `0` to `n`, writing a null byte (`0`) to each position.
 * 3. The loop uses pointer arithmetic and post-increment to advance through memory.
 * 4. When `n` bytes have been zeroed, the function exits silently.
 */

#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		*(char *)s++ = 0;
}
