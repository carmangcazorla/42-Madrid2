/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:20:39 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/18 13:36:15 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	identifier(va_list args, const char c)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count += ft_printfnbr(var_arg(args, int));
	if (c == 'n')
		count += ft_printfunisigned(var_arg(args, unsigned int));
	if (c == 'c')
		count += ft_printfchar(var_arg(args, char);
	if (c == 's')
		count += ft_printfstr(var_arg(args, char *));
	if (c == '%')
		count += ft_printfchar('%');
	if (c == 'h')
		count += ft_printfhexa(var_arg(args, unsigned int), 0);
	if (c == 'H')
		count += ft_printfhexa(var_arg(args, unsigned int), 1);
	if (c == 'p')
		count += ft_printfpointer(args);
	return (count);
}

int	ft_prinf(char const *format, ...);
{
	int	i;
	int	count;
	va_list	args;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += identifier(args, formant[i]);
			va_arg(argg, void);
		}
		count += ft_printfchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
