/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:14:52 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/13 00:24:53 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*dst_address;

	dst_address = dst;
	while (n-- > 0 && dst != src)
	{
		*(char *)dst = *(char *)src;
		dst++;
		src++;
	}
	return (dst_address);
}
