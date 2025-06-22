/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:22:50 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/22 04:47:20 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Applies function `f` to each character of `s` to create a new string with the results.
 * 
 * @headerfile Custom Function
 *
 * @param s
 * A null-terminated input string.
 *
 * @param f
 * A function that takes the index and character, returning a transformed character.
 *
 * @return char*
 * A newly allocated string resulting from applying `f` to each character of `s`, or `NULL` on allocation failure.
 *
 * @note behavior
 * Returns `NULL` if `s` is `NULL`. The result must be freed manually.
 *
 * @details
 * 1. Measure the length of `s` and allocate space for the result.
 * 2. Apply `f(i, s[i])` to each character and store the result.
 * 3. Null-terminate the result and return it.
 */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	t_len;
	char			*result;

	if (!s)
		return (NULL);
	t_len = ft_strlen(s);
	result = malloc(t_len + 1);
	if (!result)
		return (NULL);
	i = -1;
	while (++i < t_len)
		result[i] = f(i, s[i]);
	return (result[i] = '\0', result);
}
