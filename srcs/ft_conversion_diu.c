/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_diu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 05:39:10 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/07 17:37:32 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_body(int c, int n)
{
	int	x;
	int	bit;
	int	d;
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
	d = 1;
	if (bit > 0)
	{
		while ((bit / 10) != 0)
		{
			bit = bit / 10;
			d = d * 10;
		}
		while (d >= 1)
		{
			x = n / d;
			str->lenght += ft_putchar_fd(x + '0', str->fd);
			c++;
			n = n % d;
			d = d / 10;
		}
	}
	str->lenght += ft_putchar_fd(o + '0', str->fd);
	c++;
	return (c);
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
	int	len;
	int	tmp;
	int	break_flag;

	c = 0;
	len = 1;
	break_flag = 0;
	n = va_arg(lista, int);
	tmp = n;
	if (tmp < 0)
		tmp = -tmp;
	while (tmp > 10)
	{
		tmp = tmp / 10;
		len++;
	}
	str->final_width = len;
	if (str->width > len)
		str->final_width = str->width;
	if (str->precision > str->final_width)
		str->final_width = str->precision;
	// printf("\nstr width = %d\n", str->width);
	break_flag = print_before(str->final_width, len);
	c = print_body(c, n);
	print_after(str->final_width, len, break_flag);
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
	int				len;  /* insertar a la estructura */
	int				tmp;
	int				break_flag;

	c = 0;
	len = 1;
	break_flag = 0;
	num = va_arg(lista, int);
	tmp = num;
	if (tmp < 0)
		tmp = -tmp;
	while (tmp > 10)
	{
		tmp = tmp/10;
		len++;
	}
	str->final_width = len;
	if (str->width > len)
		str->final_width = str->width;
	if (str->precision > str->final_width)
		str->final_width = str->precision;
	break_flag = print_before(str->final_width, len);

	if (num == 0)
	{
		str->lenght += ft_putchar_fd('0', str->fd);
		c = 1;
	}
	if (num > 0)
	{
		div = 1;
		while ((num / div) > 9)
			div *= 10;
		while (div != 0)
		{
			str->lenght += ft_putchar_fd((num / div) + '0', str->fd);
			num %= div;
			div /= 10;
			c++;
		}
	}
	print_after(str->final_width, len, break_flag);
	return (c);
}
