/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:21:58 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/22 04:47:20 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Checks whether a given character is alphanumeric (either a letter or a digit).
 * 
 * @headerfile <ctype.h>
 *
 * @param c
 * The character to be checked, passed as an `int`. Must be representable as an `unsigned char` or be EOF.
 *
 * @return int
 * Returns `1` if the character is alphanumeric, otherwise returns `0`.
 *
 * @note behavior
 * Mimics the behavior of the standard `isalnum()` function:
 * - Only returns true for characters in the ranges `A–Z`, `a–z`, and `0–9`.
 * - Behavior is undefined if the value of `c` is not representable as an unsigned char and is not EOF.
 *
 * @details
 * 1. Check if `c` falls within the ASCII ranges for digits or letters.
 * 2. Return `1` if it's a digit (`0`–`9`) or a letter (`A`–`Z` or `a`–`z`).
 * 3. Return `0` for all other values.
 */

#include "../libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)
		|| (c >= 48 && c <= 57))
		return (1);
	return (0);
}
