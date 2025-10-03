/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:56:32 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/03 15:56:41 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	number;
	int	sing;

	number = 0;
	sing = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if(*str == '+' || *str == '-')
	{
		if(*str  == '-')
			sing = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		number *= 10;
		number += *str - 48;
		str++;
	}
	return ((sing)* number);
}
