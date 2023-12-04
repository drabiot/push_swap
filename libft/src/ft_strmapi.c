/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:54:02 by tchartie          #+#    #+#             */
/*   Updated: 2023/11/05 13:34:24 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*array;

	i = 0;
	if (!s)
		return (NULL);
	array = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!array)
		return (NULL);
	while (s[i])
	{
		array[i] = f(i, s[i]);
		i++;
	}
	array[i] = '\0';
	return (array);
}
