#include <stdlib.h>
#include "libft.h"

char	 *ft_strjoin(char const *s1, char const *s2)
{
	int	len1;
	int	len2;
	char	*str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(len1 +len2 + 1);
	if (!s1 || !s2 || !str)
		return (0); 
	while (*s1 != 0)
	{
		*str = *s1;
		*str++;
		*s1++;
	}
	while (*s2 != '\0')
	{
		*str = *s2;
		*str++;
		*s2++;
	}
	*str = '\0';
	return (str);
}
