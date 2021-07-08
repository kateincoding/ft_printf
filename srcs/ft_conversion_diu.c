/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_diu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 05:39:10 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/08 19:47:57 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	size_bit(int bit, int n, int *c)
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

int	print_body(int c, int n)
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
		size_bit(bit, n, &c);
	str->lenght += ft_putchar_fd(o + '0', str->fd);
	c++;
	return (c);
}

/*
** calculate integer len
*/

void	calculate_int_len(int num)
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

int	print_int(va_list lista)
{
	int	n;
	int	c;

	c = 0;
	str->break_flag = 0;
	n = va_arg(lista, int);
	calculate_int_len(n);
	calculate_format_width();
	str->break_flag = print_before();
	c = print_body(c, n);
	print_after();
	return (c);
}

/*
** print_unsigned - Convert a number into an unsigned int and print it
** @lista: The number to be converted
**
** Return: The number of digits printed
*/

int	print_unsigned(va_list lista)
{
	unsigned int	num;
	unsigned int	c;
	unsigned int	div;

	str->break_flag = 0;
	num = va_arg(lista, int);
	calculate_int_len(num);
	calculate_format_width();
	str->break_flag = print_before();
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
	print_after();
	return (c);
}
