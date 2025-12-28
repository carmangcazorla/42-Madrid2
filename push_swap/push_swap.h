#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
}	t_stack;

long	ft_atol(const char *str);
char	**ft_split(const char *s, char c);
void	freesplit(char **split);

int		check_intminmax(long number);
int		is_valid_number(char **split);
int		check_number(char **str);
int		checkduplicate(t_stack *stack);
int		checksorted(t_stack **stackA);

t_stack	*new_node(int num);
void	last_node(t_stack **stackA, t_stack *node);
t_stack	*create_stacka(char **argv);

void	do_rra(t_stack **stackA);
void	do_rrb(t_stack **stackB);
void	do_rrr(t_stack **stackA, t_stack **stackB);
void	rotate_down(t_stack **stack);
void	do_ra(t_stack **stackA);
void	do_rb(t_stack **stackB);
void	rotate_up(t_stack **stack);
void	do_rr(t_stack **stackA, t_stack **stackB);
void	swap(t_stack **stack);
void	do_sa(t_stack **stackA);
void	do_sb(t_stack **stackB);
void	do_ss(t_stack **stackA, t_stack **stackB);
void	do_pa(t_stack **stackA, t_stack **stackB);
void	do_pb(t_stack **stackA, t_stack **stackB);

void	sort(t_stack **stackA);
void	sort_3_num(t_stack **stackA);
void	sort_4_num(t_stack **stackA);
void	sort_5_num(t_stack **stackA);
int		count_numbers(t_stack **stackA);
int		count_bits(int size);
void	sort_large(t_stack **stackA);
void	freestack(t_stack *stackA);
void	create_index(t_stack **stackA);

#endif
