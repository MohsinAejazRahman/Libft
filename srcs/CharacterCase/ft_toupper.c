/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:01:22 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/22 04:47:20 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Converts a lowercase alphabetic character to its uppercase equivalent.
 * If the input is not a lowercase letter, it is returned unchanged.
 * 
 * @headerfile <ctype.h>
 *
 * @param c
 * The character to convert, passed as an `int` to accommodate `EOF` and extended ASCII.
 *
 * @return int
 * The uppercase equivalent of the input character if it is a lowercase letter.
 * Otherwise, returns the character unchanged.
 *
 * @note behavior
 * Mimics the behavior of the standard `toupper()` function:
 * - Only affects characters in the range `'a'` to `'z'`.
 * - Characters outside this range, including non-alphabetic symbols, are returned without modification.
 *
 * @details
 * 1. Checks whether the input character is within the ASCII range for lowercase letters (`'a'` to `'z'`).
 * 2. If it is, subtracts 32 from its ASCII value to obtain the uppercase version.
 * 3. If it is not, leaves the character unchanged.
 * 4. Returns the resulting character as an `int`.
 */

#include "../libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
