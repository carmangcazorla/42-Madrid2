/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 09:58:57 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/06 10:01:00 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int	i;

	i = 0;
	if (!s)
		return(0);
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (0);
	if (start > ft_strlen(s))
	{
		sub[i] = '\0';
		return (sub);
	}
	while (i < len && s[start] != 0)
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
#include <stdio.h>

int main(void)
{
	char *str = "hola mundo";
	char *res = ft_substr(str, 14, 10);
	printf("%s\n", res);
}
