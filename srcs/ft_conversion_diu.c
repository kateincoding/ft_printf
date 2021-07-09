/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_diu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 05:39:10 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/08 20:32:49 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	size_bit(t_fields *str, int bit, int n, int *c)
{
	int	d;
	int	x;

	d = 1;
	while ((bit / 10) != 0)
	{
		bit = bit / 10;
		d = d * 10;
	}
	while (d >= 1)
	{
		x = n / d;
		str->lenght += ft_putchar_fd(x + '0', str->fd);
		(*c)++;
		n = n % d;
		d = d / 10;
	}
}

/*
** print an integer
*/

int	print_body(t_fields *str, int c, int n)
{
	int	bit;
	int	o;

	o = n % 10;
	n = n / 10;
	if (o < 0)
	{
		n = -n;
		o = -o;
		str->lenght += ft_putchar_fd('-', str->fd);
		c++;
	}
	bit = n;
	if (bit > 0)
		size_bit(str, bit, n, &c);
	str->lenght += ft_putchar_fd(o + '0', str->fd);
	c++;
	return (c);
}

/*
** calculate integer len
*/

void	calculate_int_len(t_fields *str, int num)
{
	int	tmp;

	str->len = 1;
	tmp = num;
	if (tmp < 0)
		tmp = -tmp;
	while (tmp > 10)
	{
		tmp = tmp / 10;
		str->len++;
	}
}

/*
** print_int - It will print integers
** @lista: the main string passed to the function
** Return: An integer
*/

int	print_int(t_fields *str, va_list lista)
{
	int	n;
	int	c;

	c = 0;
	str->break_flag = 0;
	n = va_arg(lista, int);
	calculate_int_len(str, n);
	calculate_format_width(str);
	str->break_flag = print_before(str);
	c = print_body(str, c, n);
	print_after(str);
	return (c);
}

/*
** print_unsigned - Convert a number into an unsigned int and print it
** @lista: The number to be converted
**
** Return: The number of digits printed
*/

int	print_unsigned(t_fields *str, va_list lista)
{
	unsigned int	num;
	unsigned int	c;
	unsigned int	div;

	str->break_flag = 0;
	num = va_arg(lista, int);
	calculate_int_len(str, num);
	calculate_format_width(str);
	str->break_flag = print_before(str);
	c = (num == 0);
	str->lenght += ft_putchar_fd((num == 0) * '0', str->fd);
	if (num > 0)
	{
		div = 1;
		while ((num / div) > 9)
			div *= 10;
		while (div != 0)
		{
			str->lenght += ft_putchar_fd((num / div) + '0', str->fd), c++;
			num %= div;
			div /= 10;
		}
	}
	print_after(str);
	return (c);
}
