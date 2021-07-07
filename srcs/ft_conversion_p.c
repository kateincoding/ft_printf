/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:36:11 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/07 08:58:46 by ksoto            ###   ########.fr       */
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
    int len;
    int break_flag = 0;

    nb = 0;
    p = va_arg(lista, unsigned long);
    // ft_putchar(p);
    // printf("\n goku %lu\n", p);

    i = (sizeof(p) << 3) - 20;
    size = a_size(i, p, &z);
    // printf("\n size = %d\n", size);
    len = size;
    if (!p)
        len = size + 1;
    str->final_width = str->width > len ? str->width : len;
	str->final_width = str->precision > str->final_width ? str->precision : str->final_width;
	// nb += ft_putchar_fd('0', str->fd);
    // nb += ft_putchar_fd('x', str->fd);
    break_flag = print_before(str->final_width, len);
    // printf("\nsize %i vs i %i\n", size, i);
    // printf("\np = %lu\n", p);
    if (!p && str->precision == -1)
        nb += ft_putchar_fd('0', str->fd);
    while (size && i >= 0 && p != 0)
    {
        if (z-- <= 0)
            nb += ft_putchar_fd(hex_digit((p >> i) & 0xf), str->fd);
        i -= 4;
    }
    print_after(str->final_width, len, break_flag);
    str->lenght += nb;
    return(nb);
}
