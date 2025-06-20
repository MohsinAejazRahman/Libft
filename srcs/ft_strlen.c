/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:41:31 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/20 20:44:41 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Computes the length of the null-terminated string `s`, excluding the null byte.
 * 
 * @headerfile <string.h>
 *
 * @param s
 * A null-terminated string.
 *
 * @return size_t
 * The number of characters in `s` before the null terminator.
 *
 * @note behavior
 * If `s` is `NULL`, the behavior is undefined.
 *
 * @details
 * 1. Initialize a counter to zero.
 * 2. Iterate through each character in `s` until the null terminator is found.
 * 3. Return the counter as the string length.
 */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
