#include <stdlib.h>
#include "libft.h"

static char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	 *ft_strjoin(char const *s1, char const *s2)
{
	int	len1;
	int	len2;
	char	*str;

	if(!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(len1 +len2 + 1);
	if (!str)
		return (0); 
	ft_strncpy(str, (char *)s1, len1);
	ft_strncpy(str + len1, (char *)s2, len2);
	str[len1 + len2] = '\0';
	return (str);
}
#include <stdio.h>
 
int main(void)
{
	char *s1 = "hola ";
	char *s2 = "mundo";
	char *str = ft_strjoin((const char *)s1,(const char*) s2);

	printf("%s\n", str); 
}
