/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:41:12 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/13 00:26:12 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
