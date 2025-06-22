/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:11:11 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/22 04:47:20 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Checks whether a given character is an alphabetic letter (uppercase or lowercase).
 * 
 * @headerfile <ctype.h>
 *
 * @param c
 * The character to be checked, passed as an `int`. Must be representable as an `unsigned char` or be EOF.
 *
 * @return int
 * Returns `1` if the character is alphabetic, otherwise returns `0`.
 *
 * @note behavior
 * Mimics the behavior of the standard `isalpha()` function:
 * - Recognizes only ASCII letters `A–Z` and `a–z`.
 * - Behavior is undefined if the value of `c` is not representable as an unsigned char and is not EOF.
 *
 * @details
 * 1. Check if `c` falls within the ASCII ranges for uppercase (`A`–`Z`) or lowercase (`a`–`z`) letters.
 * 2. Return `1` if it is a letter.
 * 3. Return `0` for any non-letter characters.
 */

#include "../libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
