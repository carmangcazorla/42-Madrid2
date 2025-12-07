/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <carmenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:31:39 by carmenga          #+#    #+#             */
/*   Updated: 2025/12/07 13:56:59 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	*update_remainder(char *remainder)
{
	char	*updated;
	char	*temp;

	if (!remainder)
		return (NULL);
	updated = ft_strchr(remainder, '\n');
	if (!updated)
	{
		free(remainder);
		return (NULL);
	}
	temp = ft_strdup(updated + 1);
	if (!temp)
	{
		free(remainder);
		return (NULL);
	}
	free(remainder);
	remainder = temp;
	return (remainder);
}

char	*return_line(char *remainder)
{
	char	*line;
	int		i;
	int		len;

	len = 0;
	while (remainder[len] != '\0' && remainder[len] != '\n')
		len++;
	if (remainder[len] == '\n')
		len++;
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

char	*read_line(int fd, char *remainder)
{
	int		rd;
	char	*buffer;
	char	*tmp;

	if (!remainder)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(remainder), NULL);
	rd = 1;
	while (rd > 0 && !ft_strchr(remainder, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
			return (free(buffer), free(remainder), NULL);
		else if (rd > 0)
		{
			buffer[rd] = '\0';
			tmp = ft_strjoin(remainder, buffer);
			if (!tmp)
				return (free(buffer), free(remainder), NULL);
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
	remainder = read_line(fd, remainder);
	if (!remainder)
		return (free(remainder), NULL);
	if (remainder[0] == '\0')
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	line = return_line(remainder);
	if (!line)
		return (free(remainder), remainder = NULL, NULL);
	remainder = update_remainder(remainder);
	return (line);
}
 