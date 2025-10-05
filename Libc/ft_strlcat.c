/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:59:46 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/03 14:08:07 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;

	i = 0;
	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dest >= size)
	{
		return (len_src + size);
	}
	while (src[i] != '\0' && (len_dest + i) < (size - 1))
	{
		dst[len_dest + i] = src[i];
		i++;
	}
	dst[len_dest + i] = '\0';
	return (len_dest + len_src);
}
#include <stdio.h>
#include <string.h>

int main(void)
{
    char dest1[20] = "Hola";
    char dest2[20] = "Hola";

    size_t n = 10;

    size_t r1 = ft_strlcat(dest1, " mundo", n);
    size_t r2 = strlcat(dest2, " mundo", n);

    printf("ft_strlcat -> dest: '%s', return: %zu\n", dest1, r1);
    printf("strlcat    -> dest: '%s', return: %zu\n", dest2, r2);

    return 0;
}
