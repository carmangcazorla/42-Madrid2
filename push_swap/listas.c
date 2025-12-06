
t_stack new_node(int num)
{
    t_stack *node;

    node = (t_stack *)malloc(sizeof(t_stack));
    if (!node)
        return (NULL);
    node -> num = num;
    node -> next = NULL;
    return (node);
}

void  last_node(t_stack **stackA, t_stack *node)
{
    t_stack  *temp;

    if (!*stackA)
    {
        *stackA = node;
        return;
    }
    temp = *stackA;
    while (temp -> next != NULL)
        temp = temp -> next;
    temp -> next = node;
}

t_stack *create_stackA(char **argv)
{
    t_stack *stackA;
    t_stack *node;
    long    number;
    char    **split;

    stackA = NULL;
    while (*argv)
    {
        split = ft_split(*argv, ' ');
        if (!convert_check_number(split))
            return (ft_printf("Error\n"), NULL);
        while (*split)
        {
            number = ft_atol(*split);
            node = new_node(number);
            if (!node)
                return (NULL);
            last_node(&stackA, node);
            split++;
        }
        argv++;
    }
    return (stackA);
}

int checkduplicate(t_stack *stack)
{
    t_stack *node1;
    t_stack *node2;

    node1 = stack;
    while (node1)
    {
        node2 = node1 -> next;
        while (node2)
        {
            if (node1 -> num == node2 -> num)
                return (0);
            node2 = node2 -> next;
        }
        node1 = node1 -> next;
    }
    return (1);
}