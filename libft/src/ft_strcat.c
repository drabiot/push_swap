/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:31:50 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/11 17:32:22 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char const *s1, char const *s2, char *array)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		array[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		array[i + j] = s2[j];
		j++;
	}
	array[j + i] = '\0';
	return (array);
}
