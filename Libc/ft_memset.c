/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:25:27 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/03 10:50:19 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	len;

	len = 0;
	while (len < n)
	{
		(unsigned * (char)s)[len] = (unsigned char)c;
		len ++;
	}
	return (s);
}

int main(void)
{
	ft_memset("hola", 's', 10);
}
