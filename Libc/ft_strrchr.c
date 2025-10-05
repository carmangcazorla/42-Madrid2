/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:36:28 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/03 17:40:01 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	if (c == '\0')
        	return ((char *)(s + len));
	while (s[len] >= 0)
	{
		if (s[len] == c)
			return ((char *)(s + len));
		len--;
	}
	return (0);
}
#include <stdio.h>
#include <string.h>

char *ft_strrchr(const char *s, int c);

int main(void)
{
    const char *str = "hola mundo";

    printf("ft_strrchr('o') -> %s\n", ft_strrchr(str, 'o'));
    printf("strrchr('o')    -> %s\n", strrchr(str, 'o'));

    printf("ft_strrchr('a') -> %s\n", ft_strrchr(str, 'a'));
    printf("strrchr('a')    -> %s\n", strrchr(str, 'a'));

    printf("ft_strrchr('\\0') -> %p\n", ft_strrchr(str, '\0'));
    printf("strrchr('\\0')    -> %p\n", strrchr(str, '\0'));

    return 0;
}

