/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:52:57 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/22 04:46:34 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Allocates memory for an array of `nitems` elements of `size` bytes each and initializes all bytes to zero.
 * 
 * @headerfile <stdlib.h>
 *
 * @param nitems
 * The number of elements to allocate.
 *
 * @param size
 * The size in bytes of each element.
 *
 * @return void*
 * Returns a pointer to the allocated memory. If allocation fails, returns `NULL`.
 *
 * @note behavior
 * Mimics the behavior of the standard `calloc()` function:
 * - The total size is computed as `nitems * size`, which may overflow.
 * - Memory is zero-initialized using a custom implementation (`ft_bzero()`).
 * - If either `nitems` or `size` is `0`, the behavior is implementation-defined (may return `NULL` or a valid pointer).
 *
 * @details
 * 1. Multiply `nitems` by `size` to calculate the total number of bytes needed.
 * 2. Use `malloc()` to allocate that memory block.
 * 3. If allocation fails, return `NULL`.
 * 4. If successful, zero out the memory.
 * 5. Return the pointer to the allocated and zeroed memory.
 */

#include "../libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*result;

	result = malloc(nitems * size);
	if (!result)
		return (NULL);
	return (ft_bzero(result, nitems * size), result);
}
