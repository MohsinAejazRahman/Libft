/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:43:13 by mohrahma          #+#    #+#             */
/*   Updated: 2023/12/06 00:43:13 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Converts an integer to its null-terminated string representation in decimal (base 10).
 * Allocates memory dynamically to hold the resulting string. Uses helper functions
 * like `ft_mem_calc` to determine string length and `ft_strdup` for edge cases.
 * 
 * @headerfile Custom Function
 *
 * @param n
 * The integer value to convert. Supports the full range of 32-bit signed integers.
 *
 * @return char*
 * A pointer to the newly allocated string representing the integer.
 * Returns `NULL` if memory allocation fails.
 *
 * @note behavior
 * Handles the minimum integer value `-2147483648` explicitly by returning a duplicated constant string.
 * Negative numbers are represented with a leading `'-'`. Positive numbers and zero are represented without a sign.
 *
 * @details
 * 1. Check for the minimum integer edge case and return a duplicated string literal if matched.
 * 2. Use `ft_mem_calc` to calculate the required memory size, including sign if negative.
 * 3. Allocate memory for the string plus the null terminator.
 * 4. Convert the integer to a string from the end towards the start by repeatedly taking the remainder modulo 10.
 * 5. Prepend the negative sign if necessary.
 * 6. Return the allocated string.
 */

#include "../libft.h"

static int	ft_mem_calc(int n)
{
	int		sig_fig;

	sig_fig = 1;
	if (n < 0)
	{
		n = n * -1;
		sig_fig++;
	}
	while (n > 9)
	{
		n = n / 10;
		sig_fig++;
	}
	return (sig_fig);
}

char	*ft_itoa(int n)
{
	int		mem_space;
	char	*result;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 0;
	mem_space = ft_mem_calc(n);
	result = malloc(mem_space + 1);
	if (!result)
		return (NULL);
	if (n < 0)
	{
		sign = -1;
		n = n * -1;
	}
	result[mem_space] = '\0';
	while (--mem_space > -1)
	{
		result[mem_space] = (n % 10) + 48;
		n = n / 10;
	}
	if (sign == -1)
		result[0] = '-';
	return (result);
}
