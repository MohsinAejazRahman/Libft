/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:57:30 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/22 04:47:20 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Deletes and frees all elements of the list starting at `*lst` using the function `del` to free content.
 * 
 * @headerfile Custom Function
 *
 * @param lst
 * A pointer to the pointer of the first element of the list to clear.
 *
 * @param del
 * A function pointer used to free the content of each element.
 *
 * @return void
 * This function does not return a value. It frees the entire list and sets `*lst` to NULL.
 *
 * @note behavior
 * Iterates through the list, deleting each element with `ft_lstdelone` until the list is empty.
 *
 * @details
 * 1. Stores the next element temporarily.
 * 2. Calls `ft_lstdelone` on the current element.
 * 3. Advances to the next element until the list is fully cleared.
 */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	while ((*lst) != NULL)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = temp;
	}
}
