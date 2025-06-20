/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:42:02 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/20 20:54:04 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Adds the element `new` at the end of the list pointed to by `lst`.
 * 
 * @headerfile Custom Function
 *
 * @param lst
 * A pointer to the pointer of the first element of the list.
 *
 * @param new
 * The element to add at the end of the list.
 *
 * @return void
 * This function does not return a value. It modifies the list in place.
 *
 * @note behavior
 * If the list is empty (`*lst` is NULL), `new` is added as the first element by calling `ft_lstadd_front`.
 * If `new` is NULL, the function does nothing.
 * Otherwise, it appends `new` to the last element.
 *
 * @details
 * 1. Checks if the list is empty; if so, adds `new` to the front.
 * 2. If `new` is NULL, exits immediately.
 * 3. Otherwise, finds the last element using `ft_lstlast`.
 * 4. Sets the last element's `next` pointer to `new`.
 */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*address;

	if (!(*lst))
		return (ft_lstadd_front(lst, new));
	else if (!new)
		return ;
	else
	{
		address = ft_lstlast((*lst));
		address->next = new;
	}
}
