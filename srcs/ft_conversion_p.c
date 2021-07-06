/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:36:11 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/06 08:38:42 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    hex_digit(int n)
{
    if (0 <= n && n <= 9)
        return ('0' + n);
    return ('a' + n - 10);
}

int    a_size(int i, unsigned long p, int *zeroes)
{
    int    count;
    int    zcount;

    count = 0;
    *zeroes = 0;
    zcount = 0;
    while (i >= 0)
    {
        if ((p >> i & 0xf))
        {
            if (!zcount)
                *zeroes = -1;
            else if (!(*zeroes))
                *zeroes = zcount;
        }
        else
            zcount++;
        count++;
        i -= 4;
    }
    if (!p)
        count = 0;
    if (!*zeroes)
        return (count);
    return (count - *zeroes);
}

int	print_ptr(va_list lista)
{
    unsigned long p;
    int size;
	int	i;
	int	nb;
	int	z;

    nb = 0;
    p = va_arg(lista, unsigned long);
    // ft_putchar(p);
    // printf("\n goku %lu\n", p);

    i = (sizeof(p) << 3) - 20;
    size = a_size(i, p, &z);
    nb += ft_putchar_fd('0', str->fd);
    nb += ft_putchar_fd('x', str->fd);
    while (size && i >= 0)
    {
        if (z-- <= 0)
            nb += ft_putchar_fd(hex_digit((p >> i) & 0xf), str->fd);
        i -= 4;
    }
    str->lenght = nb;
    return(nb);
}
