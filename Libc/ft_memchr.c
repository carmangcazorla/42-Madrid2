/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:24:40 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/03 17:47:21 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

void *ft_memchr(const void *s, int c, size_t n)
{
	size_t i;
	unsigned char *p;

	i = 0;
	p = (unsigned char *)s;
	while(p[i] != 0 && i < n)
	{
		if (p[i] == c)
			return(&p)
		i++;
	}
	return (0);
}
