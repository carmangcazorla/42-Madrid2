/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:20:39 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/25 15:22:42 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	identifier(va_list args, const char c)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count += ft_printfnbr(va_arg(args, int));
	if (c == 'n')
		count += ft_printfunsigned(va_arg(args, unsigned int));
	if (c == 'c')
		count += ft_printfchar(va_arg(args, int));
	if (c == 's')
		count += ft_printfstr(va_arg(args, char *));
	if (c == '%')
		count += ft_printfchar('%');
	if (c == 'x')
		count += ft_printfhexa(va_arg(args, unsigned int), 0);
	if (c == 'X')
		count += ft_printfhexa(va_arg(args, unsigned int), 1);
	if (c == 'p')
		count += ft_printfpointer(va_arg(args, void *));
	return (count);
}

int	ft_printf(char const *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += identifier(args, format[i]);
			va_arg(args, void *);
			i++;
		}
		count += ft_printfchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
