/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:32:59 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/03 15:41:06 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii (int c)
{
	if (!(c >= 0 && c <= 127))
		return (0);
	else
		return (1);
}
#include <stdio.h>
int main(void)
{
    int tests[] = {0, 65, 127, 128, -1, 255};
    int size = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < size; i++)
    {
        int c = tests[i];
        printf("Valor: %d -> ft_isascii = %d\n", c, ft_isascii(c));
    }

    return 0;
}
