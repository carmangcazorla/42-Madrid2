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
