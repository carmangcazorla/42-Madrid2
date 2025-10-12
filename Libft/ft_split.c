/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 10:35:27 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/12 16:13:20 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static int	ft_counter(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		if (s[i] != c)
		{
			j++;
			i++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	return (j);
}

static char	**ft_freewords(char **arr, int i)
{
	while (i > 0)
	{
		i--;
		free(arr[i]);
	}
	free(arr);
	return (NULL);
}

static char	**init_array(char **arr, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	arr = (char **)malloc((ft_counter(s, c)) * sizeof (char *) + 1);
	if (!arr)
		return (NULL);
	while (*s != 0)
	{
		j = 0;
		while (*s != c)
		{
			*s++;
			j++;
		}
		arr[i] = (char *)malloc(j + 1);
		if (!arr[i])
			ft_freewords(arr, i);
		i++;
		while (*s == c && *s)
			s++;
	}
	return (arr);
}

char	**ft_split(char	const *s, char c)
{
	char	**arr;
	int		index;
	int		i;
	int		j;

	index = 0;
	i = 0;
	arr = init_array(arr, s, c);
	if (!arr)
		return (NULL);
	while (s[index] != 0)
	{
		j = 0;
		while (s[index] != c)
		{
			arr[i][j] = s[index];
			j++;
			index++;
		}
		arr[i][j] = '\0';
		i++;
		while (s[index] == c && s[index])
			index++;
	}
	return (arr);
}
