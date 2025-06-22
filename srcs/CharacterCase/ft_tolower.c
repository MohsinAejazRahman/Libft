/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:08:25 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/22 04:47:20 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Converts an uppercase alphabetic character to its lowercase equivalent.
 * If the input is not an uppercase letter, it is returned unchanged.
 * 
 * @headerfile <ctype.h>
 *
 * @param c
 * The character to convert, passed as an `int` to accommodate `EOF` and extended ASCII.
 *
 * @return int
 * The lowercase equivalent of the input character if it is an uppercase letter.
 * Otherwise, returns the character unchanged.
 *
 * @note behavior
 * Mimics the behavior of the standard `tolower()` function:
 * - Only affects characters in the range `'A'` to `'Z'`.
 * - Characters outside this range, including non-alphabetic symbols, are returned without modification.
 *
 * @details
 * 1. Checks whether the input character is within the ASCII range for uppercase letters (`'A'` to `'Z'`).
 * 2. If it is, adds 32 to its ASCII value to obtain the lowercase version.
 * 3. If it is not, leaves the character unchanged.
 * 4. Returns the resulting character as an `int`.
 */

#include "../libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
