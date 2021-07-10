/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:36:11 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/10 07:48:55 by ksoto            ###   ########.fr       */
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
	p = va_arg(lista, unsigned long); /* como diferenciamos cuando es 0 de un NULL */
	str->null_flag = (!p);
	// printf("p is %lu\n", p); p siempre es 0 en caso sea 0 y null, caso 3 y 6
	i = (sizeof(p) << 3) - 20;
	size = a_size(i, p, &z);
	str->len = size + (!p) * 3; /*como se diferenciaria el p de 0 y null */
	calculate_format_width(str);
	//if (!p)
	//	str->final_width += 1;
	// printf("\nlen %d and final width %d\n", str->len, str->final_width);
	print_before(str);
	if (!p && str->precision != 0)
		str->counter += ft_putchar_fd('0', str->fd);
	while (size && i >= 0 && p != 0)
	{
		if (z-- <= 0)
			str->counter += ft_putchar_fd(hex_digit((p >> i) & 0xf), str->fd);
		i -= 4;
	}
	print_after(str);
	return (str->counter);
}
