/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:35:26 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/20 20:35:30 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Checks whether a character is printable, including the space character.
 * 
 * @headerfile <ctype.h>
 *
 * @param c
 * The character to be checked, passed as an `int`. Must be representable as an `unsigned char` or be EOF.
 *
 * @return int
 * Returns `1` if the character is printable, otherwise returns `0`.
 *
 * @note behavior
 * Mimics the behavior of the standard `isprint()` function:
 * - Recognizes all ASCII values between `32` (space) and `126` (tilde).
 * - Control characters (ASCII 0–31 and 127) are not considered printable.
 *
 * @details
 * 1. Check whether the ASCII value of `c` falls within the range `32` to `126`.
 * 2. Return `1` if it is a printable character.
 * 3. Return `0` if it is a control or non-printable character.
 */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
