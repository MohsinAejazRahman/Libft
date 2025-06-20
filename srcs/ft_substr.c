/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:31:40 by mohrahma          #+#    #+#             */
/*   Updated: 2023/12/05 23:31:40 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Extracts a substring from string `s` starting at index `start`, up to `len` characters.
 * 
 * @headerfile <string.h>
 *
 * @param s
 * The input null-terminated string to extract from.
 *
 * @param start
 * The starting index of the substring.
 *
 * @param len
 * The maximum number of characters to extract.
 *
 * @return char*
 * A newly allocated substring, or an empty string if `start` is beyond the end of `s`.
 *
 * @note behavior
 * If allocation fails, `NULL` is returned. The result must be freed manually.
 *
 * @details
 * 1. Check if `start` is beyond the end of `s`; return empty string if so.
 * 2. Adjust `len` if it exceeds the remaining length.
 * 3. Allocate space and copy characters from `s + start` to the result.
 * 4. Null-terminate and return the substring.
 */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;
	int		j;

	i = 0;
	j = start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub_s = malloc((len + 1) * sizeof(char));
	if (!sub_s)
		return (NULL);
	while (s[j] != '\0' && i < len)
		sub_s[i++] = s[j++];
	return (sub_s[i] = '\0', sub_s);
}
