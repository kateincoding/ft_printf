/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:36:11 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/20 21:39:16 by ciglesia         ###   ########.fr       */
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

/*
** print_ptr - Print %p format -> address of the pointer
** @str: structure that contains all the flags
** @lista: args of the printf function
*/

int	print_ptr(t_fields *str, va_list lista)
{
	unsigned long	p;
	int				size;
	int				i;
	int				z;

	initialize_var_operators(str);
	p = va_arg(lista, unsigned long);
	str->null_flag = (!p);
	i = (sizeof(p) << 3) - 4;
	size = a_size(i, p, &z);
	str->len = size + (!p) * 3;
	calculate_format_width(str);
	print_before_p(str);
	if (!p && str->precision != 0)
		str->counter += ft_putchar_fd('0', str->fd);
	while (size && i >= 0 && p != 0)
	{
		if (z-- <= 0)
			str->counter += ft_putchar_fd(hex_digit((p >> i) & 0xf), str->fd);
		i -= 4;
	}
	print_after_p(str);
	return (str->counter);
}
