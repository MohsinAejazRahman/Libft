/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:22:50 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/13 00:38:52 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
