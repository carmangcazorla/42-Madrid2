/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 10:35:27 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/06 12:27:07 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	**ft_split(char const *s; char c)
{
	char[]	arr;
	int	i;
	int	j;
	int	index;

	index = 0;
	i = 0;
	while ((char const *)s[index] != 0)
	{
		j = 0;
		while ((char const *)s[index] != c)
		{
			arr[i][j] = (char const *)s[index];
			j++;
			index++;
		}
		index++;
		arr[i][j] = '\0';
		i++;
	}
	return (arr);
}

int main(void)
{
	char	*str = "Hola como estas hoy";
	printf("%s\n", ft_split((char const *)str,(char )' '));
}
