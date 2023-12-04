/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:24:22 by tchartie          #+#    #+#             */
/*   Updated: 2023/11/03 18:37:25 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trim_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	trim_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	while (len > i)
	{
		if (ft_strchr(set, s1[len - i - 1]) == 0)
			break ;
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_s;
	int		start;
	int		end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = trim_start(s1, set);
	end = trim_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	new_s = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!new_s)
		return (NULL);
	ft_strlcpy(new_s, &s1[start], end - start + 1);
	return (new_s);
}
