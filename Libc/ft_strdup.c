/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:07:16 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/03 16:10:59 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int	i;
	char	*dup;

	i = 0;
	while (src[i])
	{
		i++;
	}
	dup = malloc(i + 1);
	if (!dup)
	{
		return (NULL);
	}
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ft_strdup(const char *src);

int main(void)
{
    const char *original = "Hola mundo!";
    char *duplicado = ft_strdup(original);
    char *duplicado_real = strdup(original);

    if (!duplicado || !duplicado_real)
    {
        printf("Error al asignar memoria\n");
        return (1);
    }

    printf("Cadena original      : %s\n", original);
    printf("ft_strdup (tu copia) : %s\n", duplicado);
    printf("strdup (original)    : %s\n", duplicado_real);

    // Verificamos si apuntan a distintas direcciones de memoria
    printf("Dirección original   : %p\n", (void *)original);
    printf("Dirección ft_strdup  : %p\n", (void *)duplicado);
    printf("Dirección strdup     : %p\n", (void *)duplicado_real);

    free(duplicado);
    free(duplicado_real);

    return 0;
}
