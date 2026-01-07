/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <carmenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:27:10 by carmenga          #+#    #+#             */
/*   Updated: 2026/01/07 10:27:11 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pa(t_stack **stackA, t_stack **stackB)
{
	t_stack	*temp;

	if (!stackB || !*stackB)
		return ;
	temp = *stackB;
	*stackB = (*stackB)->next;
	temp -> next = *stackA;
	*stackA = temp;
	write(1, "pa\n", 3);
}

void	do_pb(t_stack **stackA, t_stack **stackB)
{
	t_stack	*temp;

	if (!stackA || !*stackA)
		return ;
	temp = *stackA;
	*stackA = (*stackA)->next;
	temp->next = *stackB;
	*stackB = temp;
	write(1, "pb\n", 3);
}
