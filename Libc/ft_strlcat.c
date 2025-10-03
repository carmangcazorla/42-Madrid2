/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:59:46 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/03 14:08:07 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int static	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len_dest;
	unsigned int	len_src;

	i = 0;
	j = 0;
	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dest < size)
	{
		return (len_src + size);
	}
	while (src[i] != '\0' && len_src + i < size - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (len_dest + len_src);
}
