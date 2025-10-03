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
#include <stddef.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;
	unsigned char *p;
	unsigned char *c;

	i = 0;
	p = (unsigned char *)s1;
	c = (unsigned char *)s2;
	while ((p[i] != '\0' && c[i] != '\0' && i < n -1) && p[i] == c[i])
	{
		i++;
	}
	return (p[i] - c[i]);
}

#include <stdio.h>
int main(void)
{
	char arr[]="holaaa";
	char arr2[] ="holas";
	printf("%d\n",ft_memcmp(arr, arr2, 5));
}

