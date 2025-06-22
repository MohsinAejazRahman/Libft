/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:45:01 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/22 04:47:20 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Writes a null-terminated string to the specified file descriptor.
 * 
 * @headerfile <unistd.h>
 *
 * @param s
 * The string to be written. Must be a valid pointer to a null-terminated character array.
 *
 * @param fd
 * The file descriptor to which the string `s` will be written.
 *
 * @return void
 * This function does not return a value. It directly writes the string to the output stream represented by `fd`.
 *
 * @note behavior
 * Mimics the behavior of a raw string write using `write()`:
 * - Writes each character individually without buffering.
 * - No newline or formatting is added.
 * - If `s` is `NULL`, behavior is undefined.
 *
 * @details
 * 1. Loop through the string `s` one character at a time.
 * 2. For each character, call `write()` with the file descriptor and the character address.
 * 3. The function stops writing once the null terminator (`'\0'`) is reached.
 * 4. The function performs no validation or output formatting.
 */

#include "../libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	while (s[++i] != '\0')
		write(fd, &s[i], 1);
}
