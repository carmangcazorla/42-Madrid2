/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:13:50 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/18 14:13:57 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_printfchar(char c);
void	ft_printfstr(char *str);
void	ft_printfnbr(int n);
void	ft_printfunsigned(unsigned int n);
void    ft_printfhexa(int n);
void    ft_printfHexa(int n);
void    ft_printfpointer(void *ptr);
int		printfiteri(char const *str, void argument);
void	identifier(char c, void va_list(args, void));
void	ft_prinf(char const *str, ...);

#endif
