/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:13:50 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/25 15:18:06 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printfchar(char c);
int	ft_printfstr(char *str);
int	ft_printfnbr(int n);
int	ft_printfunsigned(unsigned int n);
int	ft_printfhexa(unsigned int n, int uppercase);
int	ft_printfpointer(void *ptr);
int	ft_printptrhexa(unsigned long long ptr);
int	identifier(va_list args, const char c);
int	ft_printf(char const *str, ...);

#endif
