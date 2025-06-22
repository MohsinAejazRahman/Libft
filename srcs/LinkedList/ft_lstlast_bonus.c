/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 01:08:01 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/22 04:47:20 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Returns the last element of the list `lst`.
 * 
 * @headerfile Custom Function
 *
 * @param lst
 * The first element of the list.
 *
 * @return t_list*
 * Returns a pointer to the last element of the list, or `lst` itself if the list is empty.
 *
 * @note behavior
 * Traverses the list until it finds the element whose `next` is `NULL`.
 *
 * @details
 * 1. Checks if `lst` is NULL; returns it immediately if so.
 * 2. Iterates through elements until `lst->next` is NULL.
 * 3. Returns the last element found.
 */

#include "../libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!(lst))
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
