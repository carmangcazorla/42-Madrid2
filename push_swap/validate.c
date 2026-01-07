/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <carmenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:42:24 by carmenga          #+#    #+#             */
/*   Updated: 2026/01/07 10:42:25 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_intminmax(long number)
{
	if (number < -2147483648 || number > 2147483647)
		return (0);
	return (1);
}

int	is_valid_number(char **split)
{
	int	i;
	int	j;

	i = 0;
	if (!split || !split[0])
		return (0);
	while (split[i])
	{
		j = 0;
		if (split[i][j] == '-' || split[i][j] == '+')
			j++;
		if (!split[i][j])
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
	if (!is_valid_number(str))
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

int	checkduplicate(t_stack *stack)
{
	t_stack	*node1;
	t_stack	*node2;

	node1 = stack;
	while (node1)
	{
		node2 = node1 -> next;
		while (node2)
		{
			if (node1 -> num == node2 -> num)
				return (0);
			node2 = node2 -> next;
		}
		node1 = node1 -> next;
	}
	return (1);
}

int	checksorted(t_stack **stackA)
{
	t_stack	*temp;

	if (!stackA || !(*stackA))
		return (0);
	temp = *stackA;
	while (temp -> next)
	{
		if (temp -> num > temp -> next -> num)
			return (0);
		temp = temp -> next;
	}
	return (1);
}
