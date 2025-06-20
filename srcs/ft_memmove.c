/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:41:12 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/20 20:38:05 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Copies `len` bytes from memory area `src` to memory area `dst`, safely handling overlapping memory regions.
 * 
 * @headerfile <string.h>
 *
 * @param dst
 * A pointer to the destination memory area.
 *
 * @param src
 * A pointer to the source memory area.
 *
 * @param len
 * The number of bytes to copy.
 *
 * @return void*
 * Returns the original value of `dst`.
 *
 * @note behavior
 * Mimics the behavior of the standard `memmove()` function:
 * - Safely handles overlapping memory regions by copying in the correct direction.
 * - If `dst < src`, it copies forward.
 * - If `dst > src`, it copies backward to prevent overwriting.
 *
 * @details
 * 1. Store the original destination address for returning.
 * 2. If `dst < src`, copy forward from start to end.
 * 3. If `dst > src`, adjust both pointers and copy backward from end to start.
 * 4. If `dst == src`, no action is taken.
 */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void		*dst_add;

	dst_add = dst;
	if (dst < src)
		while (len-- > 0)
			*(char *)dst_add++ = *(char *)src++;
	else if (dst > src)
	{
		dst_add += len;
		src += len;
		while (len-- > 0)
			*(char *)--dst_add = *(char *)--src;
	}
	return (dst);
}
