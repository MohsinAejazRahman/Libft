/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:09:46 by mohrahma          #+#    #+#             */
/*   Updated: 2023/12/06 00:09:46 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Concatenates two strings into a newly allocated string.
 * 
 * @headerfile <string.h>
 *
 * @param s1
 * The first null-terminated string to join.
 *
 * @param s2
 * The second null-terminated string to join.
 *
 * @return char*
 * A newly allocated string containing the contents of `s1` followed by `s2`, or `NULL` on allocation failure.
 *
 * @note behavior
 * Returns `NULL` if either `s1` or `s2` is `NULL`. The result must be freed manually.
 *
 * @details
 * 1. Compute the total length needed by summing the lengths of `s1` and `s2`.
 * 2. Allocate enough space for both strings and a null terminator.
 * 3. Copy `s1` into the result, then append `s2`.
 * 4. Null-terminate and return the result.
 */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	if (s1 == 0 || s2 == 0)
		return (0);
	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		result[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
		result[i++] = s2[j];
	return (result[i] = '\0', result);
}
