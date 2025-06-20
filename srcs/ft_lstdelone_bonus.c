/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:45:11 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/20 20:54:43 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Deletes a single element `lst` by applying `del` to its content and freeing the element itself.
 * 
 * @headerfile Custom Function
 *
 * @param lst
 * The element to delete.
 *
 * @param del
 * A function pointer used to free the content of the element.
 *
 * @return void
 * This function does not return a value. It frees the element and its content.
 *
 * @note behavior
 * Calls `del` on `lst->content` and then frees the element pointer.
 *
 * @details
 * 1. Applies `del` function to `lst->content`.
 * 2. Frees the memory allocated to `lst`.
 */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}
