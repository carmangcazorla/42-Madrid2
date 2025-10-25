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
	while (str[i])
	{
		count += ft_printfchar(str[i]);
		i++;
	}
	count += ft_printfchar('\0');
	return (count);
}

int	ft_printfnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		ft_printfstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_printfchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_printfnbr(n / 10);
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
		ft_printfunsigned(n / 10);
	}
	count += ft_printfchar((n % 10) + '0');
	return (count);
}

int	main(void)
{
	ft_printfchar('A');
	ft_printfchar('\n');
	ft_printfstr("Hello, World!");
	ft_printfchar('\n');
	ft_printfnbr(-12345);
	ft_printfchar('\n');
	ft_printfunsigned(67890);
	ft_printfchar('\n');
	ft_printfpercent();
	ft_printfchar('\n');
	return (0);
}
