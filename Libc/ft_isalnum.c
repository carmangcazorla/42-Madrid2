/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:29:20 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/03 15:32:27 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum (int c)
{
	if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c  <= '9')))
		return (0);
	else
		return (1);
}
#include <stdio.h>
int main(void)
{
    char test[] = {'A', 'z', '0', '9', '!', ' ', '\n'};
    int size = sizeof(test) / sizeof(test[0]);

    for (int i = 0; i < size; i++)
    {
        char c = test[i];
        printf("Char: '%c' (ASCII %d) -> ft_isalnum = %d\n",
               (c >= 32 && c <= 126) ? c : '.', // imprime '.' si no es imprimible
               c, ft_isalnum(c));
    }

    return 0;
}
