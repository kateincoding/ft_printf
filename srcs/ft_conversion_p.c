/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:36:11 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/08 21:02:53 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	hex_digit(int n)
{
	if (0 <= n && n <= 9)
		return ('0' + n);
	return ('a' + n - 10);
}

int	a_size(int i, unsigned long p, int *zeroes)
{
	int	count;
	int	zcount;

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
	unsigned long	p;
	int				size;
	int				i;
	int				nb;
	int				z;

	nb = 0;
	str->break_flag = 0;
	p = va_arg(lista, unsigned long);
	i = (sizeof(p) << 3) - 20;
	size = a_size(i, p, &z);
	str->len = size + (!p);
	calculate_format_width();
	str->break_flag = print_before();
	if (!p && str->precision == -1)
		nb += ft_putchar_fd('0', str->fd);
	while (size && i >= 0 && p != 0)
	{
		if (z-- <= 0)
			nb += ft_putchar_fd(hex_digit((p >> i) & 0xf), str->fd);
		i -= 4;
	}
	print_after();
	str->lenght += nb;
	return (nb);
}
