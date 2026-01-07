/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <carmenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:27:24 by carmenga          #+#    #+#             */
/*   Updated: 2026/01/07 10:27:25 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_down(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	do_rra(t_stack **stackA)
{
	rotate_down(stackA);
	write(1, "rra\n", 4);
}

void	do_rrb(t_stack **stackB)
{
	rotate_down(stackB);
	write(1, "rrb\n", 4);
}

void	do_rrr(t_stack **stackA, t_stack **stackB)
{
	rotate_down(stackA);
	rotate_down(stackB);
	write(1, "rrr\n", 4);
}
