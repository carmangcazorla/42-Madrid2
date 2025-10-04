/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:09:18 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/03 10:14:41 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
	{
		return (0);
	}
	else
	{
		return(1);
	}
}
#include <stdio.h>

int ft_isdigit(int c);

int main(void)
{
    char tests[] = {'0', '5', '9', 'A', '-', ' '};
    int size = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < size; i++)
    {
        char c = tests[i];
        printf("Char: '%c' (ASCII %d) -> ft_isdigit = %d\n",
               (c >= 32 && c <= 126) ? c : '.', c, ft_isdigit(c));
    }

    return 0;
}
