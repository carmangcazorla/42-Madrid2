#include <stdlib.h>

char    *ft_strmapi(char *s, char (*f)(unsigned int, char))
{
        int     i;
        char    *str;

        i = 0;
        if (!s || !f)
                return (NULL);
        str = (char *)malloc(ft_strlen(s) + 1);        
        if (!str)
                return (NULL);
        while (s[i])
        {
                str[i] = f(i, s[i]);
                i++;
        }
        str[i] = '\0';
        return (str);
}

