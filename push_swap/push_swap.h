# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
    int				num;
    struct s_list	*next;
}                   t_stack;

int     ft_atol(const char *str);
int	    convert_check_number(char **str);
int     checkduplicate(char **split);
int     is_valid_number(char **split);
int     ft_printf(const char *format, ...);
char	**ft_split(const char *s, char c);
t_stack	*create_stackA(char **argv);
# endif