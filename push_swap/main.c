

int main(int argc, char **argv)
{
    t_stack *stackA;

    if (argc < 2)
        return (0);
    stackA = create_stackA(argv);
    if (!stackA)
        return (ft_printf("Error\n"), 0);
    if (!checkduplicate(stackA))
        return (ft_printf("Error\n"), 0);
}
