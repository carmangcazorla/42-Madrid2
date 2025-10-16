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

static int	ft_counter(char const *s, char c)
{
	int	words;

	words = 0;
	if (!s)
		return (0);
	while (*s != 0)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
	}
	return (words);
}

static char	**ft_freewords(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (arr);
}

static int	ft_countletters(char const *s, int i, char c)
{
	int	count;

	count = 0;
	if (c == '\0')
		while (s[i++])
			count++;
	while (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

static char	**init_array(char **arr, char const *s, char c)
{
	int	i;
	int	j;
	int	k;
	int	len;

	i = 0;
	k = 0;
	while (s[k] != 0)
	{
		while (s[k] == c && s[k])
			k++;
		len = ft_countletters(s, k, c);
		if (len > 0)
		{
			arr[i] = (char *)malloc(len + 1);
			if (!arr[i])
				return (ft_freewords(arr), NULL);
			j = 0;
			while (s[k] && s[k] != c && len-- > 0)
				arr[i][j++] = s[k++];
			arr[i][j] = '\0';
			i++;
		}
	}
	return (arr[i] = NULL, arr);
}

char	**ft_split(char	const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char **)malloc((ft_counter(s, c) + 1) * sizeof (char *));
	if (!arr)
		return (NULL);
	arr = init_array(arr, s, c);
	return (arr);
}
