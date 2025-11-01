#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char	*save_remainder(char *line)
{
	static char	*save;
	char	*next_line;

	next_line = ft_strchr(line,'\n');
	if (next_line)
		save = ft_strdup(next_line + 1);
	return(save);
}

char	*read_line(int fd, char *save)
{
	int	rd;
	char	*buffer;
	char	*line;

	rd = 1;
	line = NULL;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (rd > 0 && !ft_strchr(line, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd > 0)
		{
			buffer[rd] = '\0';
			line = ft_strjoin(buffer, line);
		}
	}
	save_remainder(line);
	free (buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char	*line;

	line = read_line(fd, save);
	save = save_remainder(line);
	return (line);
}

int main(void)
{
    char *line;

    printf("Escribe algo (Ctrl+D para salir):\n");

    // 🔁 Bucle: sigue leyendo mientras haya datos
    while ((line = get_next_line(0)) != NULL)
    {
        printf("Has escrito: %s\n", line);
        free(line);
    }

    printf("\nFin de la entrada.\n");
    return (0);
}
