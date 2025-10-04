/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:11:03 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/03 14:22:36 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	len;

	len = 0;
	while (len < n)
	{
		((char*)s)[len] = 0;
		len ++;
	}
}
#include <stdio.h>
int main(void)
{
    char buffer[] = "hola mundo";

    printf("Antes: %s\n", buffer);
    ft_bzero(buffer, 3);  // Pone a 0 los tres primeros chars
    printf("Después (con printf directo): %s\n", buffer);

    // Para ver los bytes, mejor imprimir manualmente:
    printf("Bytes después de bzero:\n");
    for (size_t i = 0; i < sizeof(buffer); i++)
    {
        if (buffer[i] == 0)
            printf("\\0 ");
        else
            printf("%c ", buffer[i]);
    }
    printf("\n");

    return 0;
}
