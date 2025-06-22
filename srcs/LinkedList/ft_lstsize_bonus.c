/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 01:04:48 by mohrahma          #+#    #+#             */
/*   Updated: 2025/06/22 04:47:20 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Counts the number of elements in the list `lst`.
 * 
 * @headerfile Custom Function
 *
 * @param lst
 * The first element of the list.
 *
 * @return int
 * The number of elements in the list.
 *
 * @note behavior
 * Iterates through the list, incrementing a counter for each element.
 *
 * @details
 * 1. Initialize a counter to zero.
 * 2. Loop through each element of the list until `lst` is NULL.
 * 3. Increment the counter for each element.
 * 4. Return the final count.
 */

#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
