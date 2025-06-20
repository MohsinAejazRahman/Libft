/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:03:32 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/20 20:44:45 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Appends `src` to `dst`, ensuring the result fits within `dstsize` and is null-terminated.
 * 
 * @headerfile <string.h>
 *
 * @param dst
 * The destination buffer. Must be null-terminated if not empty.
 *
 * @param src
 * The source null-terminated string to append.
 *
 * @param dstsize
 * The total size of the destination buffer.
 *
 * @return size_t
 * The total length the resulting string would have had if there was enough space.
 *
 * @note behavior
 * The return value allows detection of truncation. No null-termination occurs if `dstsize` is 0.
 *
 * @details
 * 1. Measure the length of `dst` and ensure it does not exceed `dstsize`.
 * 2. Append characters from `src` to `dst` until space runs out.
 * 3. Null-terminate `dst` if there is room.
 * 4. Return the intended total length.
 */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	t_len;

	d_len = 0;
	s_len = 0;
	while (dst[d_len] != '\0' && d_len < dstsize)
		d_len++;
	t_len = d_len + ft_strlen(src);
	if (d_len == dstsize)
		return (t_len);
	while (src[s_len] != '\0' && (d_len + s_len) < dstsize - 1)
	{
		dst[d_len + s_len] = src[s_len];
		s_len++;
	}
	dst[d_len + s_len] = '\0';
	return (t_len);
}
