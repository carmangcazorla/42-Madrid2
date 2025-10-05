#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)malloc(count * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, count * size);
        	return (ptr);
}
