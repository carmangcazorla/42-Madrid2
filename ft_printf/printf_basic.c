/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 10:26:33 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/18 10:42:55 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printfchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printfstr(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
	{
		count += ft_printfstr("(null)");
		return (count);
	}
	while (str[i])
	{
		count += ft_printfchar(str[i]);
		i++;
	}
	return (count);
}

int	ft_printfnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_printfstr("-2147483648");
		return (count);
	}
	if (n < 0)
	{
		count += ft_printfchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		count += ft_printfnbr(n / 10);
	}
	count += ft_printfchar((n % 10) + '0');
	return (count);
}

int	ft_printfunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_printfunsigned(n / 10);
	}
	count += ft_printfchar((n % 10) + '0');
	return (count);
}
