/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:41:40 by tchartie          #+#    #+#             */
/*   Updated: 2023/11/06 14:48:28 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*array;

	array = (t_list *)malloc(sizeof(t_list));
	if (!array)
		return (NULL);
	array->content = content;
	array->next = NULL;
	return (array);
}
