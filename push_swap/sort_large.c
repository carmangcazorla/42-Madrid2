/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <carmenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:42:45 by carmenga          #+#    #+#             */
/*   Updated: 2026/01/07 10:42:46 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while (size >> max_bits)
		max_bits++;
	return (max_bits);
}

void	sort_large(t_stack **stackA)
{
	int		i;
	int		max_bits;
	int		j;
	int		size;
	t_stack	*stackb;

	j = 0;
	size = count_numbers(stackA);
	max_bits = count_bits(size);
	stackb = NULL;
	while (j < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((*stackA)->index >> j) & 1)
				do_ra(stackA);
			else
				do_pb(stackA, &stackb);
			i++;
		}
		while (stackb)
			do_pa(stackA, &stackb);
		j++;
	}
}
