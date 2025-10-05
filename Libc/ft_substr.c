#include "libft.h"
#include <stddef.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	sub =(char *)malloc(len + 1);
	if(!sub)
	{
		return(0);
	}
	if (start > ft_strlen(s))
	{
		sub[i] = '\0';
		return (sub);
	}
	while (s[i] != 0 && i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
