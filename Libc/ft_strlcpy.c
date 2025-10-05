/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:24:21 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/03 13:53:52 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
	dst[i] = '\0';
	}
	return (len);
}

#include <stdio.h>
#include <string.h>

size_t  ft_strlcpy(char *dst, const char *src, size_t size);

int main(void)
{
    char destino1[4];
    char destino2[4];
    const char *origen = "hola mundo";

    size_t r1 = ft_strlcpy(destino1, origen, sizeof(destino1));
    size_t r2 = strlcpy(destino2, origen, sizeof(destino2));

    printf("ft_strlcpy -> '%s', return: %zu\n", destino1, r1);
    printf("strlcpy    -> '%s', return: %zu\n", destino2, r2);

    return 0;
}
