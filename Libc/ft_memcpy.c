/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:38:08 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/03 17:02:02 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;
	unsigned char *p;
	unsigned char *c;

	i = 0;
	p = (unsigned char *)dst;
	c = (unsigned char *)src;
	while(i < n)
	{
		p[i] = c[i];
		i++;
	}
	p[i] = 0;
	return (p);
}
