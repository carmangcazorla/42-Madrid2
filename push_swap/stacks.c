#include "push_swap.h"

t_stack	*new_node(int num)
{
	t_stack	*node;
	int		index;

	index = 0;
	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node -> num = num;
	node -> index = index;
	node -> next = NULL;
	return (node);
}

void	last_node(t_stack **stackA, t_stack *node)
{
	t_stack	*temp;

	if (!*stackA)
	{
		*stackA = node;
		return ;
	}
	temp = *stackA;
	while (temp -> next != NULL)
		temp = temp -> next;
	temp -> next = node;
}

int	add_numbers(char *arg, t_stack **stackA)
{
	t_stack	*node;
	char	**temp;
	long	number;
	char	**split;

	split = ft_split(arg, ' ');
	if (!check_number(split) || !split)
		return (freesplit(split), 0);
	temp = split;
	while (*temp)
	{
		number = ft_atol(*temp);
		node = new_node((int)number);
		if (!node)
			return (freesplit(split), 0);
		last_node(stackA, node);
		temp++;
	}
	freesplit(split);
	return (1);
}

t_stack	*create_stacka(char **argv)
{
	t_stack	*stacka;

	stacka = NULL;
	while (*argv)
	{
		if (!add_numbers(*argv, &stacka))
			return (freestack(stacka), NULL);
		argv++;
	}
	return (stacka);
}

void	create_index(t_stack **stackA)
{
	t_stack	*temp;
	t_stack	*next;
	int		index;

	temp = *stackA;
	while (temp)
	{
		index = 1;
		next = *stackA;
		while (next)
		{
			if (temp->num > next->num)
				index += 1;
			next = next -> next;
		}
		temp -> index = index;
		temp = temp -> next;
	}
}
