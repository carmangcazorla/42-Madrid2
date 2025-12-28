#include "push_swap.h"

void	freestack(t_stack *stackA)
{
	t_stack	*temp;

	while (stackA)
	{
		temp = stackA;
		stackA = stackA->next;
		free(temp);
	}
}

void	freesplit(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
