/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_diu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 05:39:10 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/10 06:29:44 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	size_bit(t_fields *str, int bit, int n)
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
		str->counter += ft_putchar_fd(x + '0', str->fd);
		n = n % d;
		d = d / 10;
	}
}

/*
** print an integer
*/

void	print_body(t_fields *str, int n)
{
	int	bit;
	int	o;

	o = n % 10;
	n = n / 10;
	if (o < 0)
	{
		n = -n;
		o = -o;
		str->counter += ft_putchar_fd('-', str->fd);
	}
	bit = n;
	if (bit > 0)
		size_bit(str, bit, n);
	if (!(str->zero_value == 1 && str->precision == 0))
		str->counter += ft_putchar_fd(o + '0', str->fd);
}

/*
** calculate integer len
*/

void	calculate_int_len(t_fields *str, int num)
{
	int	tmp;

	tmp = num;
	if (tmp < 0)
	{
		if (str->op == 'i' || str->op == 'd')
			str->len++;
		while (tmp < -10)
		{
			tmp = tmp / 10;
			str->len++;
		}
		if (tmp > -10)
			str->len += 1;
	}
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		str->len++;
	}
	if (tmp < 10 && tmp >= 0)
		str->len += 1;
	if (str->zero_value)
		str->len = 0;
}

/*
** print_int - It will print integers
** @lista: the main string passed to the function
** Return: An integer
*/

int	print_int(t_fields *str, va_list lista)
{
	int	n;

	initialize_var_operators(str);
	n = va_arg(lista, int);
	if (n > 0)
		str->positive = 1;
	else if (n == 0)
		str->zero_value = 1;
//	printf("\nlen = %d\n", str->len);
	calculate_int_len(str, n);
//	printf("\nlen = %d\n", str->len);
	calculate_format_width(str);
//	printf("\nfinal width = %d\n", str->final_width);
	print_before(str);
	print_body(str, n);
	print_after(str);
	return (str->counter);
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
	unsigned int	div;

	initialize_var_operators(str);
	num = va_arg(lista, int);
	if (num > 0)
		str->positive = 1;
	else if (num == 0)
		str->zero_value = 1;
	calculate_int_len(str, num);
	calculate_format_width(str);
	print_before(str);
//	if (num == 0)
//		str->counter += ft_putchar_fd('0', str->fd);
	if (num > 0)
	{
		div = 1;
		while ((num / div) > 9)
			div *= 10;
		while (div != 0)
		{
			str->counter += ft_putchar_fd((num / div) + '0', str->fd);
			num %= div;
			div /= 10;
		}
	}
	print_after(str);
	return (str->counter);
}
