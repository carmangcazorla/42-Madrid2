/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:31:39 by carmenga          #+#    #+#             */
/*   Updated: 2025/11/02 17:31:47 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*update_remainder(char *remainder)
{
	char	*update;
	char	*temp;

	update = ft_strchr(remainder, '\n');
	if (!update)
	{
		free(remainder);
		return (NULL);
	}
	temp = ft_strdup(update + 1);
	if (!temp)
	{
		free(remainder);
		return (NULL);
	}
	free(remainder);
	remainder = temp;
	return(remainder);
}

char	*return_line(char *remainder)
{
	char	*line;
	int		len;
	int		i;

	len = 0;
	while (remainder[len] != '\n' && remainder[len] != '\0')
		len++;
	if (remainder[len] == '\n')
		len ++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = remainder[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_file(int fd, char *remainder)
{
	char	*buffer;
	int		rd;
    char    *tmp;

	rd = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(remainder), NULL);
	while (rd > 0 && !ft_strchr(remainder, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(remainder);
			free(buffer);
			return (NULL);
		}
		if (rd > 0)
		{
			buffer[rd] = '\0';
			tmp = ft_strjoin(remainder, buffer);
			if (!tmp)
				return (free(buffer), NULL);
			remainder = tmp;
		}
	}
	return (free(buffer), remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!remainder)
		remainder = ft_strdup("");
	remainder = read_file(fd, remainder);
    if (!remainder)
		return (NULL);
	if (!remainder[0])
	{
    	free(remainder);
   		remainder = NULL;
		return(NULL);
	}
	line = return_line(remainder);
	if (!line)
		return (NULL);
	remainder = update_remainder(remainder);
	return (line);
}
