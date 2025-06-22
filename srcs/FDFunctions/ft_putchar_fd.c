/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:52:12 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/22 04:47:20 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Writes a single character to the specified file descriptor.
 * 
 * @headerfile <unistd.h>
 *
 * @param c
 * The character to be written.
 *
 * @param fd
 * The file descriptor to which the character `c` will be written.
 *
 * @return void
 * This function does not return a value. It performs a write operation directly on the file descriptor.
 *
 * @note behavior
 * Mimics the behavior of the `write()` system call for a single character:
 * - Does not validate if `fd` is open or writable.
 * - If `fd` is invalid or closed, the function has undefined behavior.
 * - No newline or null-terminator is appended automatically.
 *
 * @details
 * 1. Take the address of the character `c` and pass it to the `write()` system call.
 * 2. Write exactly 1 byte to the given file descriptor `fd`.
 * 3. The system call handles the actual I/O; no internal buffering is performed.
 */

#include "../libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
