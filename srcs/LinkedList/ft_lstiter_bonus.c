/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:17:36 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/22 04:47:20 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Iterates over the list `lst` and applies the function `f` to the content of each element.
 * 
 * @headerfile Custom Function
 *
 * @param lst
 * The first element of the list to iterate through.
 *
 * @param f
 * A function pointer to apply to the content of each element.
 *
 * @return void
 * This function does not return a value. It applies `f` to each element's content.
 *
 * @note behavior
 * The function `f` is called on each element’s content in order until the end of the list.
 *
 * @details
 * 1. Loops through each element starting at `lst`.
 * 2. Calls function `f` with `lst->content` as an argument.
 * 3. Moves to the next element until `lst` is NULL.
 */

#include "../libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
