/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:59:28 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/06 16:36:53 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

int    ft_countnum(int n)
{
        int     count;

        count = 0;
        if (n < 0)
        {
                count++;
                n *= -1;
        }
        while (n)
        {
                count++;
                n /= 10;
        }
        return (count);
}

char    *ft_itoa(int n)
{
        char    *str;
        int     i;
        long int    nb;

        i = ft_countnum(n);
        nb = n;
        str = (char *)malloc(i + 1);
        if (!str)
                return (0);
        str[i--] = '\0';
        if (nb == 0)
        {
            str[0] = '0';
        }
        if (nb < 0)
        {
                str[0] = '-';
                nb = -nb;
        }
        while (nb > 0)
        {
                str[i--] = (nb % 10) + '0';
                nb /= 10;
        }
        return (str);
}

#include <stdio.h>

int main(void)
{
    printf("Caso 1: n = 12345 → %s\n", ft_itoa(12345));   // normal
    printf("Caso 2: n = 0 → %s\n", ft_itoa(0));           // número 0
    printf("Caso 3: n = -12345 → %s\n", ft_itoa(-12345)); // número negativo
    printf("Caso 4: n = 10 → %s\n", ft_itoa(10));           // un solo dígito
    printf("Caso 5: n = -9 → %s\n", ft_itoa(-9));         // negativo simple
    printf("Caso 6: n = 2147483647 → %s\n", ft_itoa(2147483647));   // INT_MAX
    printf("Caso 7: n = -2147483648 → %s\n", ft_itoa(-2147483648)); // INT_MIN
}
