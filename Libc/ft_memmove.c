#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;
        unsigned char *p;
        unsigned char *c;

        i = 0;
        p = (unsigned char *)dst;
        c = (unsigned char *)src;
	if (c > p)
        	while(i < len)
        	{
                	p[i] = c[i];
                	i++;
        	}
	if (p > c)
		while (0 < len)
		{
			len--;
			p[len] = c[len];
		}
        return (p);
}
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[20] = "123456789";

    printf("Antes: %s\n", str);
    ft_memmove(str + 2, str, 5); // mover los primeros 5 caracteres a partir del índice 2
    printf("Después: %s\n", str);

    return 0;
}
