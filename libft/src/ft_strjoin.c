/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:05:24 by tchartie          #+#    #+#             */
/*   Updated: 2023/11/07 13:34:59 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!s1)
		buffer = (char *)malloc(sizeof(char) * (len_s2 + 1));
	else
		buffer = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!buffer)
		return (NULL);
	buffer = ft_strcat(s1, s2, buffer);
	return (buffer);
}
