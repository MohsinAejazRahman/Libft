/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:14:52 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/20 20:37:35 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Copies `n` bytes from memory area `src` to memory area `dst`. The memory areas must not overlap.
 * 
 * @headerfile <string.h>
 *
 * @param dst
 * A pointer to the destination memory area.
 *
 * @param src
 * A pointer to the source memory area.
 *
 * @param n
 * The number of bytes to copy.
 *
 * @return void*
 * Returns the original value of `dst`.
 *
 * @note behavior
 * Mimics the behavior of the standard `memcpy()` function:
 * - If memory areas overlap, the behavior is undefined.
 * - If `n == 0`, the function does nothing.
 * - If `dst == src`, the copy is skipped to avoid unnecessary writes.
 *
 * @details
 * 1. Save the initial address of `dst` for returning at the end.
 * 2. Cast both `dst` and `src` to `char *` for byte-wise copying.
 * 3. Iterate over `n` bytes and copy each byte from `src` to `dst`.
 * 4. Return the saved destination pointer.
 */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*dst_address;

	dst_address = dst;
	while (n-- > 0 && dst != src)
		*(char *)dst++ = *(char *)src++;
	return (dst_address);
}
