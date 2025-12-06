
t_stack sa(t_stack *stackA)
{
    t_stack *first;
    t_stack *second;

    if (!stackA || !stackA->next)
        return (stackA);
    first = stackA;
    second = stackA->next;
    first->next = second->next;
    second->next = first;
    return (second);
}

t_stack pa(t_stack **stackA, t_stack **stackB)
{
    t_stack *temp;

    if (!*stackA || !*stackB)
        return;
    temp = *stackB;
    *stackB = (*stackB)->next;
    temp->next = *stackA;
    *stackA = temp;
    return ;
}