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
		return(NULL);
	}
	temp = ft_strdup(update + 1);
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
		return(NULL);
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

	rd = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (rd > 0 && !ft_strchr(remainder, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
			return (free(buffer), NULL);
		if (rd > 0)
		{
			buffer[rd] = '\0';
			remainder = ft_strjoin(remainder, buffer);
			if (!remainder)
				return (free(buffer), NULL);
		}
	}
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	
	if (!remainder)
		remainder = ft_strdup("");
	if (!remainder)
		return (NULL);
	remainder = read_file(fd, remainder);
    if (!remainder)
		return NULL;
	if (!remainder[0])
	{
    	free(remainder);
   		remainder = NULL;
		return NULL;
	}
	line = return_line(remainder);
	remainder = update_remainder(remainder);
	return (line);
}

//#include <stdio.h>

/*int main(void)
{
    char *line;

    printf("Escribe algo:\n");
    while ((line = get_next_line(0)) != NULL)
	{
        printf("Has escrito:%s", line);
        free(line);
    }
   printf("\nFin de la entrada.\n");
    return 0;
}

//gcc -Wall -Wextra -Werror -DBUFFER_SIZE=32 get_next_line.c get_next_line_utils.c

#include <fcntl.h>
#include <unistd.h>

/*int main(void)
{
    int fd;
    char *line;

    fd = open("texto.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    printf("\nFin de la lectura.\n");
    return 0;
}