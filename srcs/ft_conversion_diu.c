/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_diu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 05:39:10 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/01 21:05:12 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
*print_int - It will print integers
*@lista: the main string passed to the function
*Return: An integer
*/
int print_int(va_list lista)
{
	int x, bit, d, o, n, c = 0;
	int width, len = 1, tmp, i;

	n = va_arg(lista, int);
	tmp = n;
	if (tmp < 0)
		tmp = -tmp;
	while(tmp < 10)
	{
		tmp = tmp/10;
		len++;
	}
	/* handle flags , also needs to see precision*/
	width = str->width > len ? str->width : len;
	if(str->minus == 0 && width != len)
	{
		i = 1;
		while(i < (width - len))
		{
			str->lenght = ft_putchar_fd(' ', str->fd);
			i++;
		}
	}
	/* printing number */
	o = n % 10;
	n = n / 10;
	if (o < 0)
	{
		n = -n;
		o = -o;
		str->lenght = ft_putchar_fd('-', str->fd);
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
			str->lenght = ft_putchar_fd(x + '0', str->fd);
			c++;
			n = n % d;
			d = d / 10;
		}
	}
	str->lenght = ft_putchar_fd(o + '0', str->fd);
	if(str->minus != 0 && width != len)
	{
		i = 1;
		while(i < (width - len))
		{
			str->lenght = ft_putchar_fd(' ', str->fd);
			i++;
		}
	}
	c++;
	return (c);
}

/**
* print_unsigned - Convert a number into an unsigned int and print it
* @lista: The number to be converted
*
* Return: The number of digits printed
*/
int print_unsigned(va_list lista)
{
	unsigned int num, c = 0, div;

	num = va_arg(lista, int);

	if (num == 0)
	{
		ft_putchar_fd('0', str->fd);
		c = 1;
	}
	if (num > 0)
	{
		for (div = 1; (num / div) > 9; div *= 10)
			;
		while (div != 0)
		{
			ft_putchar_fd((num / div) + '0', str->fd);
			num %= div;
			div /= 10;
			c++;
		}
	}
	return (c);
}
