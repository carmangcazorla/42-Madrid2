/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:59:28 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/06 16:36:53 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_strrev(char *str, char *dst)
{
	int	i;
	int	j;
	
	i = ft_strlen(str);
	j = 0;
	while(i >= 0)
	{
		dst[j] = str[i]
		j++;
		i--;
	}
	dest
}
char	*ft_itoa(int n)
{
	char	*str;
	char	*dst;
	int	i;
	int	j;

	i = 0;
	if (n < 0)
		dst[i] = '-';
		n *= -1;
		i++;
	while(n > 0)
	{
		str[i] = '0' + (n % 10);
		n /= 10;
		i++;
	}
	dst = (char *)malloc(ft_strlen(str) + 1);
	if (!dst)
		return (0);
	ft_strrev(str, dst);
	dst[j] = '\0';
	return (dst);
}

#include <stdio.h>
int main(void)
{
	int	t;
	t = 12345;
	printf("%s\n", ft_itoa(t));
}
