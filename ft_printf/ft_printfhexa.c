/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfhexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:11:45 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/18 11:16:35 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_printfhexa(unsigned int n, int uppercase)
{
        int     count;

        count = 0;
        if (n >= 16)
            count += ft_printfhexa(n / 16, uppercase);
        else if (n == 0)
            count += ft_printfchar('0');
        if ((n % 16) < 10)
            count += ft_printfchar((n % 16) + '0');
        else if (uppercase)
            count += ft_printfchar(((n % 16) - 10) + 'A');
        else
            count += ft_printfchar(((n % 16) - 10) + 'a');
        return (count);
}

int	ft_printptrhexa(unsigned long ptr)
{
	int	count;

	count = 0;
	if (ptr >= 16)
            count += ft_printptrhexa(ptr / 16);
        if ((ptr % 16) < 10)
            count += ft_printfchar((ptr % 16) + '0');
        else
            count += ft_printfchar(((ptr % 16) - 10) + 'a');
	return (count);
}

int ft_printfpointer(unsigned long ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (ft_printfstr("(nil)"));
	count += ft_printfstr("0x");
	count += ft_printptrhexa(ptr);
        return (count);
}
