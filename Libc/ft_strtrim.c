#include "libft.h"
#include <stdlib.h>

int static	ft_chrcmp(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
        	i++;
	}
	return (0);
}

char    *ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int	end;
	int	start;
	int	i;

	end = ft_strlen(s1) - 1;
	start = 0;
	i = 0;
	while (s1[start] && ft_chrcmp(s1[start], set))
		start++;
	while (start < end  && ft_chrcmp(s1[end], set))
		end--;
	p = (char *)malloc(end - start + 2);
	if (!p)
		return(0);
	while (start < end)
	{
		p[i] = s1[start];
		start++;
		i++;
	}
	p[i] = '\0';
	return(p);
}

#include <stdio.h>
#include <stdlib.h>

char    *ft_strtrim(char const *s1, char const *set);

int main(void)
{
    char *res;

    res = ft_strtrim("***hola***", "*");
    printf("Caso 1 -> '%s'\n", res);
    free(res);
    res = ft_strtrim("...42Madrid", ".");
    printf("Caso 2 -> '%s'\n", res);
    free(res);
    res = ft_strtrim("hello!!!", "!");
    printf("'%s'\n", res);
    free(res);
    res = ft_strtrim("libft", "*");
    printf("'%s'\n", res);
    free(res);
    res = ft_strtrim("xxxxx", "x");
    printf("'%s'\n", res);
    free(res);
    res = ft_strtrim("", "abc");
    printf("'%s'\n", res);
    free(res);

    return (0);
}
