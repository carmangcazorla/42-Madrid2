/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:04:09 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/03 17:19:31 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*p;
	unsigned const char	*c;

	i = 0;
	p = (unsigned const char *)s1;
	c = (unsigned const char *)s2;
	while (i < n)
	{
		if (p[i] != c[i])
			return (p[i] - c[i]);
		i++;
	}
	return (0);
}
