/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfhexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:11:45 by carmenga          #+#    #+#             */
/*   Updated: 2025/10/18 11:16:35 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_printfhexa(int n)
{
    char    *hexa;
    int     mod;
    int     i;

    i = 0;
    while(n > 0)
    {
        mod = n % 16;
        if (mod >= 0 && mod <= 10)
            hexa[i] =(char)(mod + '0');
        if (mod > 10 && mod < 16)
            hexa[i] = (char)((mod - 10) + 'a');
        n = n / 16;
        i++;
    }
    hexa[i++] = ((n / 16) + '0');
    while (i >= 0)
    {
        ft_printfchar(hexa[i]);
        i--;
    }
    ft_printfchar('\0');
    return (ft_strlen(hexa));
}

int    ft_printfHexa(int n)
{
    char *hexa;
    int  mod;
    int  i;

    i = 0;
    while(n > 0)
    {
        mod = n % 16;
        if (mod >= 0 && mod <= 10)
            hexa[i] =(char)(mod + '0');
        if (mod > 10 && mod < 16)
            hexa[i] = (char)((mod - 10) + 'A');
        n = n / 16;
        i++;
    }
    hexa[i++] = ((n / 16) + '0');
    while (i >= 0)
    {
        ft_printfchar(hexa[i]);
        i--;
    }
    ft_printfchar('\0');
    return (ft_strlen(hexa));
}

int ft_printfpointer(int n)
{
    while (n > 0)
    {
        ft_printfstr("0x");
    }
}

int main(void)
{
    ft_printfhexa(255);
    return (0);
}