/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:29:00 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/20 20:55:12 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Creates a new list by applying the function `f` to the content of each element of `lst`.
 * If allocation fails, clears the new list using `del`.
 * 
 * @headerfile Custom Function
 *
 * @param lst
 * The original list to map over.
 *
 * @param f
 * A function pointer to apply to each element’s content.
 *
 * @param del
 * A function pointer to free content in case of failure.
 *
 * @return t_list*
 * Returns a pointer to the new mapped list or `NULL` on failure.
 *
 * @note behavior
 * For each element in `lst`, applies `f` to its content and adds the result to the new list.
 * If memory allocation fails at any point, cleans up and returns `NULL`.
 *
 * @details
 * 1. Initializes an empty result list.
 * 2. Iterates over `lst`, applies `f` to each content.
 * 3. Creates a new element with the result of `f`.
 * 4. If allocation fails, calls `del` on the mapped content, clears lists, and returns `NULL`.
 * 5. Adds new elements to the back of the result list.
 * 6. Returns the newly created list.
 */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*address;
	void	*f_res;

	result = NULL;
	if (!(lst || f))
		return (NULL);
	while (lst != NULL)
	{
		f_res = f(lst->content);
		address = ft_lstnew(f_res);
		if (!address)
		{
			del(f_res);
			ft_lstclear(&address, del);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, address);
		lst = lst->next;
	}
	return (result);
}
