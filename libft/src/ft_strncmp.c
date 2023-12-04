/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:01:10 by tchartie          #+#    #+#             */
/*   Updated: 2023/11/01 18:45:41 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*sent1;
	unsigned char	*sent2;

	i = 0;
	sent1 = (void *)s1;
	sent2 = (void *)s2;
	while (((sent1[i] || sent2[i]) && (sent1[i] - sent2[i] == 0)) && (n > i))
		i++;
	if (n == i)
		return (0);
	return (sent1[i] - sent2[i]);
}
