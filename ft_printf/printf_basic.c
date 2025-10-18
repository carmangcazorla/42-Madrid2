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

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

int	ft_printfstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_printfchar(str[i]);
		i++;
	}
	ft_printfchar('\0');
	return (ft_strlen(str));
}

int	ft_countnum(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count++;
	}
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	ft_printfnbr(int n)
{
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
	ft_printfchar((n % 10) + '0');
	return (ft_countnum(n) + 1);
}

void	ft_printfunsigned(unsigned int n)
{
	if (n >= 10)
	{
		ft_printfunsigned(n / 10);
	}
	ft_printfchar((n % 10) + '0');
	return (ft_countnum(n) + 1);
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