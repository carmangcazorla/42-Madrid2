/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:25:27 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/03 16:37:16 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	unsigned char *p;

	
	p = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		p[i] = c;
		i ++;
	}
	return (b);
}
