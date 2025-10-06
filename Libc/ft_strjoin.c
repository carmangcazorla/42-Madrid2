#include <stdlib.h>
#include "libft.h"

static char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int

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

	len1 = ft_strlen((const char *)s1);
	len2 = ft_strlen((const char *)s2);
	str = (char *)malloc(len1 +len2 + 1);
	if (!s1 || !s2 || !str)
		return (0); 
	while (*s1 != 0)
	{
		ft_strncpy((char *)str, (char *)s1, len1);
	}
	while (*s2 != '\0')
	{
		ft_strncpy((char *)str, (char *)s2, len2);
	}
	*str = '\0';
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
