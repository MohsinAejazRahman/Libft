/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:04:00 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/22 04:47:20 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Writes an integer to the specified file descriptor as a series of characters.
 * 
 * @headerfile <unistd.h>
 *
 * @param n
 * The integer value to be written. Handles both positive and negative values.
 *
 * @param fd
 * The file descriptor to which the number will be written.
 *
 * @return void
 * This function does not return a value. It recursively performs write operations on the file descriptor.
 *
 * @note behavior
 * Mimics behavior of basic `printf` or `itoa` logic for integer output:
 * - Handles the edge case for `INT_MIN` directly to avoid overflow.
 * - Recursively breaks the number into digits from most significant to least.
 * - Does not include any formatting, padding, or newline character.
 *
 * @details
 * 1. If `n` equals `INT_MIN` (-2147483648), write the string literal manually and return.
 * 2. If `n` is negative, write a '-' character and convert `n` to its positive equivalent.
 * 3. If `n` is greater than 9, recursively call the function with `n / 10` to process higher-order digits.
 * 4. Calculate the final digit using `n % 10`, convert it to ASCII by adding 48, and write it.
 * 5. This approach ensures left-to-right digit output without using strings or buffers.
 */

#include "../libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	value;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n = -n;
			write(fd, "-", 1);
		}
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		value = (n % 10) + 48;
		write(fd, &value, 1);
	}
}
