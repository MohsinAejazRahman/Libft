/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 00:58:38 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/22 04:47:20 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Adds the element `new` at the beginning of the list pointed to by `lst`.
 * 
 * @headerfile Custom Function
 *
 * @param lst
 * A pointer to the pointer of the first element of the list.
 *
 * @param new
 * The element to add at the front of the list.
 *
 * @return void
 * This function does not return a value. It modifies the list in place.
 *
 * @note behavior
 * Sets `new->next` to the current first element and updates `*lst` to `new`.
 *
 * @details
 * 1. Assigns `new->next` to the current list head.
 * 2. Updates the list head to `new`.
 */

#include "../libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = (*lst);
	(*lst) = new;
}
