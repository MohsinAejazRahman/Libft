/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:34:39 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/20 20:44:49 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Applies function `f` to each character of the string `s`, passing its index and address.
 * 
 * @headerfile <string.h>
 *
 * @param s
 * A mutable null-terminated string to be iterated over.
 *
 * @param f
 * A function that takes the index and a pointer to each character in `s`.
 *
 * @return void
 * The function modifies `s` in place using the behavior defined by `f`.
 *
 * @note behavior
 * If `s` is `NULL`, the function does nothing. The function pointer must not be `NULL`.
 *
 * @details
 * 1. Loop through the string using its length.
 * 2. For each index `i`, call `f(i, &s[i])`.
 * 3. Continue until all characters have been visited.
 */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = -1;
	while (++i < ft_strlen(s))
		f(i, &s[i]);
}
