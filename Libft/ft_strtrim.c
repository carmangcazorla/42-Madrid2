/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:01:45 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/10 19:01:53 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

int static	ft_chrcmp(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		end;
	int		start;
	int		i;

	end = ft_strlen(s1) - 1;
	start = 0;
	i = 0;
	while (s1[start] && ft_chrcmp(s1[start], set))
		start++;
	while (start < end && ft_chrcmp(s1[end], set))
		end--;
	p = (char *)malloc(end - start + 2);
	if (!p)
		return (0);
	while (start < end)
	{
		p[i] = s1[start];
		start++;
		i++;
	}
	p[i] = '\0';
	return (p);
}
