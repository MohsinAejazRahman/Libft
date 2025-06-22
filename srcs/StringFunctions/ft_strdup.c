/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:47:31 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/22 04:47:20 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Allocates memory and duplicates the string `s1`.
 * 
 * @headerfile <string.h>
 *
 * @param s1
 * A null-terminated string to be duplicated.
 *
 * @return char*
 * A pointer to a newly allocated string containing a copy of `s1`, or `NULL` on allocation failure.
 *
 * @note behavior
 * The returned string is null-terminated and allocated with `malloc()`. It must be freed manually.
 *
 * @details
 * 1. Allocate memory for the copy of `s1` including space for the null terminator.
 * 2. Copy each character from `s1` into the new buffer.
 * 3. Null-terminate the result and return its pointer.
 */

#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		i;

	result = malloc(ft_strlen(s1) + 1);
	if (!result)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		result[i] = s1[i];
	return (result[i] = '\0', result);
}
