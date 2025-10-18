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

int	printfiteri(char const *str, void va_list(args, void));
{
	int	i;

	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			identifier(str[i]; argument);
		}
		else
			printfiteri(str[i]);
		i++;
	}
}

void	identifier(char c, void va_list(args, void))
{
	if (c == 'd' || c == 'i')
		ft_printfnbr(args);
	if (c == 'n')
		ft_printfunisigned(args);
	if (c == 'c')
		ft_printfchar(args);
	if (c == 's')
		ft_printfstr(args);
	if (c == '%')
		ft_printfchar('%');
	if (c == 'h')
		ft_printfhexa(args);
	if (c == 'H')
		ft_printfHexa(args);
	if (c == 'p')
		ft_printfpointer(args);
}

void	ft_prinf(char const *str, ...);
{
	va_list	args;

	va_start(args, void);
	while (args)
	{
		printfiteri(str, va_list(args, void));
		va_arg(argg, void);
	}
	va_end(args);
}