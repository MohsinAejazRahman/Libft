/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:44:23 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/22 04:47:20 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Checks whether a given character is a decimal digit (`0`–`9`).
 * 
 * @headerfile <ctype.h>
 *
 * @param c
 * The character to be checked, passed as an `int`. Must be representable as an `unsigned char` or be EOF.
 *
 * @return int
 * Returns `1` if the character is a digit, otherwise returns `0`.
 *
 * @note behavior
 * Mimics the behavior of the standard `isdigit()` function:
 * - Recognizes only ASCII characters between `'0'` and `'9'`.
 * - Behavior is undefined if the value of `c` is not representable as an unsigned char and is not EOF.
 *
 * @details
 * 1. Check if `c` falls between ASCII values `48` and `57` (inclusive).
 * 2. Return `1` if the character is a valid digit.
 * 3. Return `0` for all non-digit inputs.
 */

#include "../libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
