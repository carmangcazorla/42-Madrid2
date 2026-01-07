/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <carmenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:42:40 by carmenga          #+#    #+#             */
/*   Updated: 2026/01/07 10:42:41 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_numbers(t_stack **stackA)
{
	t_stack	*temp;
	int		num;

	num = 0;
	temp = *stackA;
	while (temp)
	{
		temp = temp->next;
		num++;
	}
	return (num);
}

void	sort(t_stack **stackA)
{
	int	num;

	num = count_numbers(stackA);
	if (num <= 1)
		return ;
	else if (num == 2)
	{
		if ((*stackA)->num > (*stackA)->next->num)
			do_sa(stackA);
		return ;
	}
	else if (num == 3)
		sort_3_num(stackA);
	else if (num == 4)
		sort_4_num(stackA);
	else if (num == 5)
		sort_5_num(stackA);
	else
		sort_large(stackA);
}

void	sort_3_num(t_stack **stackA)
{
	int	a;
	int	b;
	int	c;

	a = (*stackA)->num;
	b = (*stackA)->next->num;
	c = (*stackA)->next->next->num;
	if (a < b && b < c)
		return ;
	else if (a > b && b < c && a < c)
		do_sa(stackA);
	else if (a > b && b < c && a > c)
		do_ra(stackA);
	else if (a < b && b > c && a < c)
	{
		do_sa(stackA);
		do_ra(stackA);
	}
	else if (a < b && b > c && a > c)
		do_rra(stackA);
	else if (a > b && b > c)
	{
		do_sa(stackA);
		do_rra(stackA);
	}
}

void	sort_4_num(t_stack **stackA)
{
	t_stack	*stackb;
	int		size;

	size = count_numbers(stackA);
	stackb = NULL;
	while (size > 3)
	{
		if ((*stackA)->index == 1)
		{
			do_pb(stackA, &stackb);
			size--;
		}
		else
			do_ra(stackA);
	}
	sort_3_num(stackA);
	do_pa(stackA, &stackb);
}

void	sort_5_num(t_stack **stackA)
{
	t_stack	*stackb;
	int		size;

	stackb = NULL;
	size = count_numbers(stackA);
	while (size > 3)
	{
		if ((*stackA)->index <= 2)
		{
			do_pb(stackA, &stackb);
			size--;
		}
		else
			do_ra(stackA);
	}
	sort_3_num(stackA);
	if (stackb->index < stackb->next->index)
		do_sb(&stackb);
	do_pa(stackA, &stackb);
	do_pa(stackA, &stackb);
}
