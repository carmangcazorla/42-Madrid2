/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:23:42 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/09 14:23:48 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*c;

	i = 0;
	p = (unsigned char *)dst;
	c = (unsigned char *)src;
	if (c > p)
	{
		while (i < len)
		{
			p[i] = c[i];
			i++;
		}
	}
	if (p > c)
	{
		while (0 < len)
		{
			len--;
			p[len] = c[len];
		}
	}
	return (p);
}
