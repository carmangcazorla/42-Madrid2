/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <carmenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:27:16 by carmenga          #+#    #+#             */
/*   Updated: 2026/01/07 10:27:17 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_up(t_stack **stack)
{
	t_stack	*first;
	t_stack	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	first->next = NULL;
}

void	do_ra(t_stack **stackA)
{
	rotate_up(stackA);
	write(1, "ra\n", 3);
}

void	do_rb(t_stack **stackB)
{
	rotate_up(stackB);
	write(1, "rb\n", 3);
}

void	do_rr(t_stack **stackA, t_stack **stackB)
{
	rotate_up(stackA);
	rotate_up(stackB);
	write(1, "rr\n", 3);
}
