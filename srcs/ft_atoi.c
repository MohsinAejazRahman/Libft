/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:45:54 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/20 20:29:38 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Converts a string into an integer, replicating the behavior of the standard `atoi()` function.
 * 
 * @headerfile <stdlib.h>
 *
 * @param str
 * A null-terminated C string representing the number to convert.
 * The string may start with leading whitespace and an optional sign ('+' or '-').
 *
 * @return int
 * The converted integer value from the string, respecting sign and skipping whitespace.
 * Returns 0 if no digits are found after optional whitespace and sign.
 *
 * @note behavior
 * Mimics the behavior of the original `atoi()`:
 * - No error is raised for invalid characters.
 * - Stops parsing at the first non-digit character.
 * - Does not handle overflow or underflow. (undefined behavior)
 *
 * @details
 * 1. Skip leading whitespace and control characters (ASCII 9–13 & 32).
 * 2. Checks for a single and optional '+' or '-' to determine sign.
 * 3. Iterate through digits ('0'–'9') and construct result using positional math:
 *    result = result * 10 + (digit - '0').
 * 4. Return the result multiplied by the sign.
 */


#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
		result = (result * 10) + (str[i++] - 48);
	return (result * sign);
}
