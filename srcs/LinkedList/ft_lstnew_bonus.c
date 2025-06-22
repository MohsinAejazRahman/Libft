/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 00:41:09 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/22 04:47:20 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Allocates and returns a new element with `content`. The `next` pointer is set to NULL.
 * 
 * @headerfile Custom Function
 *
 * @param content
 * The content to store in the new element.
 *
 * @return t_list*
 * Returns a pointer to the newly allocated element or `NULL` if allocation fails.
 *
 * @note behavior
 * Allocates memory for the new element and initializes its members.
 *
 * @details
 * 1. Allocates memory for a `t_list` struct.
 * 2. Sets `content` to the passed argument.
 * 3. Sets `next` to `NULL`.
 * 4. Returns the new element or `NULL` if memory allocation failed.
 */

#include "../libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*address;

	address = malloc(sizeof(t_list));
	if (!(address))
		return (NULL);
	address->content = content;
	address->next = NULL;
	return (address);
}
