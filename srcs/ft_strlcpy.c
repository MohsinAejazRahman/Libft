/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:11:08 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/20 20:44:43 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Copies up to `dstsize - 1` characters from `src` to `dst`, null-terminating the result.
 * 
 * @headerfile <string.h>
 *
 * @param dst
 * The destination buffer where the string is copied.
 *
 * @param src
 * The source null-terminated string to copy.
 *
 * @param dstsize
 * The size of the destination buffer including space for the null terminator.
 *
 * @return size_t
 * The total length of `src`, which allows detection of truncation.
 *
 * @note behavior
 * If `dstsize` is 0, no characters are copied but the length of `src` is still returned.
 *
 * @details
 * 1. Measure the length of `src`.
 * 2. If `dstsize` is non-zero, copy up to `dstsize - 1` characters into `dst`.
 * 3. Null-terminate `dst` if space permits.
 * 4. Return the full length of `src` regardless of copied length.
 */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src,
	size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	while (src[j] != '\0')
		j++;
	if (dstsize == 0)
		return (j);
	while (src[++i] != '\0' && i + 1 < dstsize)
		dst[i] = src[i];
	return (dst[i] = '\0', j);
}
