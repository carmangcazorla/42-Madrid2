/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <carmenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:27:04 by carmenga          #+#    #+#             */
/*   Updated: 2026/01/07 10:27:05 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first -> next;
	first -> next = second -> next;
	second -> next = first;
	*stack = second;
}

void	do_sa(t_stack **stackA)
{
	swap(stackA);
	write(1, "sa\n", 3);
}

void	do_sb(t_stack **stackB)
{
	swap(stackB);
	write(1, "sb\n", 3);
}

void	do_ss(t_stack **stackA, t_stack **stackB)
{
	swap(stackA);
	swap(stackB);
	write(1, "ss\n", 3);
}
