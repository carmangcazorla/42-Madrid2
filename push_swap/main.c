#include "push_swap.h"

/*void print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("%d ", stack->num);
        stack = stack->next;
    }
    printf("\n");
}*/

int	main(int argc, char **argv)
{
	t_stack	*stacka;

	if (argc < 2)
		return (0);
	stacka = create_stacka(argv + 1);
	if (!stacka)
		return (write(2, "Error\n", 6), 0);
	if (!checkduplicate(stacka))
		return (freestack(stacka), write(2, "Error\n", 6), 0);
	create_index(&stacka);
	if (checksorted(&stacka))
		return (freestack(stacka), 0);
	sort(&stacka);
	freestack(stacka);
	return (0);
}
