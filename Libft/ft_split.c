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

static int	ft_word_count(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static int	ft_word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	ft_free(char **arr, int i)
{
	while (--i >= 0)
		free(arr[i]);
	free(arr);
}

static char	**ft_fill_words(char **arr, const char *s, char c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			len = ft_word_len(s, c);
			arr[i] = (char *)malloc(sizeof(char) * (len + 1));
			if (!arr[i])
			{
				ft_free(arr, i);
				return (NULL);
			}
			j = 0;
			while (j < len)
				arr[i][j++] = *s++;
			arr[i++][j] = '\0';
		}
	}
	return (arr[i] = NULL, arr);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!arr)
		return (NULL);
	return (ft_fill_words(arr, s, c));
}
