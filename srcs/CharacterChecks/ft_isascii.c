/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:29:42 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/22 04:47:20 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Checks whether a given integer value corresponds to a valid ASCII character.
 * 
 * @headerfile <ctype.h>
 *
 * @param c
 * The integer to be checked. Can be any `int` value.
 *
 * @return int
 * Returns `1` if `c` is within the ASCII range (0–127), otherwise returns `0`.
 *
 * @note behavior
 * Mimics the behavior of the standard `isascii()` function:
 * - Only values between `0` and `127` inclusive are considered ASCII.
 * - This function does not depend on locale or character encoding.
 *
 * @details
 * 1. Check whether the value of `c` is greater than or equal to 0 and less than or equal to 127.
 * 2. Return `1` if `c` is within the ASCII range.
 * 3. Return `0` for any extended or invalid values.
 */

#include "../libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
