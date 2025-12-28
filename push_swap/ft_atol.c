#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	number;
	int		sing;

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
