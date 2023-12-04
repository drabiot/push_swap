/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:26:39 by tchartie          #+#    #+#             */
/*   Updated: 2023/11/06 23:33:41 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*array;

	if (lst)
	{
		while (*lst)
		{
			array = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = array;
		}
	}
}
