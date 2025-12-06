/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:56:32 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/12 15:32:47 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *str)
{
	long	number;
	int	sing;

	number = 0;
	sing = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sing = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		number *= 10;
		number += *str - 48;
		str++;
	}
	return ((sing) * number);
}

int	check_intminmax(long number)
{
	if (number < -2147483648 || number > 2147483647)
		return (0);
	return (1);
}

int is_valid_number(char **split)
{
    int i;
    int j;

    i = 0;
    if (!split || !split[0])
        return (0);
    while (split[i])
    {
        j = 0;
        if (split[i][j] == '-' || split[i][j] == '+')
            j++;
        if(!split[i][j])
            return (0);
        while (split[i][j])
        {
            if (split[i][j] < '0' || split[i][j] > '9')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int	check_number(char **str)
{
	long	number;
	int		i;

	if (!str)
		return (0);
	if(!is_valid_number(str))
		return (0);
	i = 0;
	while (str[i])
	{
		number = ft_atol(str[i]);
		if (!check_intminmax(number))
			return (0);
		i++;
	}
	return (1);
}