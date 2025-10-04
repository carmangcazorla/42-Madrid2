/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:28:37 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/03 17:33:40 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while(*s != 0)
	{
		if (*s ==(char) c)
			return((char *)s);
		s++;
	}
	if (c == '\0')
		return((char *)s);
	return (0);
}
#include <stdio.h>
#include <string.h>

int main(void)
{
    const char *texto = "hola mundo";

    // Buscar caracter existente
    printf("ft_strchr(\"%s\", 'm') = %s\n", texto, ft_strchr(texto, 'm'));
    printf("strchr(\"%s\", 'm')    = %s\n", texto, strchr(texto, 'm'));

    // Buscar caracter inexistente
    printf("ft_strchr(\"%s\", 'z') = %s\n", texto, ft_strchr(texto, 'z'));
    printf("strchr(\"%s\", 'z')    = %s\n", texto, strchr(texto, 'z'));

    // Buscar terminador
    printf("ft_strchr(\"%s\", '\\0') = %p\n", texto, ft_strchr(texto, '\0'));
    printf("strchr(\"%s\", '\\0')    = %p\n", texto, strchr(texto, '\0'));

    return 0;
}

