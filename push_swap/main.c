

int main(int argc, char **argv)
{
    t_stack *stackA;

    if (argc < 2)
        return (0);
    stackA = create_stackA(argv);
    if (!stackA)
        return (ft_printf("Error\n"), 0);
    valid = checkduplicate(stackA);
    if (valid == 0)
        return (ft_printf("Error\n"), 0);
}
