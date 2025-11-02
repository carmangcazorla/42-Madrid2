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

char	*save_remainder(char *line)
{
	static char	*save;
	char		*next_line;

	next_line = ft_strchr(line,'\n');
	if (next_line)
		save = ft_strdup(next_line + 1);
	return(save);
}

void	ft_free(char *save)
{
	if (save)
	{
		free (save);
	}
}

char	*read_line(int fd, char *save)
{
	int		rd;
	char	*buffer;

	rd = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		return (NULL);
		ft_free(save);
	}
	while (rd > 0 && !ft_strchr(save, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd > 0)
		{
			buffer[rd] = '\0';
			save = ft_strjoin(buffer, save);
		}
	}
	save_remainder(save);
	free (buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	line = read_line(fd, save);
	save = save_remainder(line);
	return (line);
}
#include <stdio.h>

int main(void)
{
    char *line;

    printf("Escribe algo:\n");
    while ((line = get_next_line(0)) != NULL)
    {
        printf("Has escrito: %s\n", line);
        free(line);
    }
    printf("\nFin de la entrada.\n");
    return (0);
}
