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
	while(i < n)
	{
		if (p[i] == (unsigned char)c)
			return((void *)(p + 1));
		i++;
	}
	return (0);
}
#include <stdio.h>
int main(void)
{
    char str[] = "hola mundo";

    // Buscar un caracter que existe
    char *res1 = ft_memchr(str, 'm', 10);
    printf("Buscando 'm' en \"%s\" -> %s\n", str, res1);

    // Buscar un caracter que no existe
    char *res2 = ft_memchr(str, 'z', 10);
    printf("Buscando 'z' en \"%s\" -> %s\n", str, res2 ? res2 : "NULL");

    // Buscar el carácter nulo
    char *res3 = ft_memchr(str, '\0', 20);
    printf("Buscando '\\0' en \"%s\" -> %p\n", str, (void *)res3);

    return 0;
}
