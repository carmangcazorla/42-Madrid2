/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:38:08 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/03 10:54:25 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memcpy(void *d, const void *s, size_t len)
{
	size_t	i;

	i = 0;
	while(i < len)
	{
		((char *)d)[i] = ((char *)s)[i];
		i++;
	}
	((unsigned char *)d)[i] = 0;
	return (d);
}

int main(void)
{
	ft_memcpy("hola", "mundo", 3);
}
