/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:08:27 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/22 04:47:20 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Writes a string followed by a newline character to the specified file descriptor.
 * 
 * @headerfile <unistd.h>
 *
 * @param s
 * The null-terminated string to be written. Must not be `NULL`.
 *
 * @param fd
 * The file descriptor to which the string and newline will be written.
 *
 * @return void
 * This function does not return a value. It performs sequential write operations directly on the file descriptor.
 *
 * @note behavior
 * Mimics the behavior of writing with `write()`:
 * - Writes each character of the string individually, followed by a newline.
 * - Does not check if `s` is `NULL`; dereferencing a null pointer causes undefined behavior.
 * - No internal buffering or formatting is applied.
 *
 * @details
 * 1. Iterate through the string `s` one character at a time until the null terminator is reached.
 * 2. Use `write()` to output each character to `fd`.
 * 3. After the full string has been written, write a newline character (`'\n'`) to `fd`.
 * 4. The function completes without returning a value.
 */

#include "../libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = -1;
	while (s[++i] != '\0')
		write(fd, &s[i], 1);
	write(fd, "\n", 1);
}
