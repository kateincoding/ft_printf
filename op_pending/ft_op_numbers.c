/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:39:00 by ksoto             #+#    #+#             */
/*   Updated: 2021/06/27 14:04:07 by ciglesia         ###   ########.fr       */
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

	n = va_arg(lista, int);
	o = n % 10;
	n = n / 10;
	if (o < 0)
	{
		n = -n;
		o = -o;
		ft_putchar('-');
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
			ft_putchar(x + '0');
			c++;
			n = n % d;
			d = d / 10;
		}
	}
	ft_putchar(o + '0');
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
		ft_putchar('0');
		c = 1;
	}
	if (num > 0)
	{
		for (div = 1; (num / div) > 9; div *= 10)
			;
		while (div != 0)
		{
			ft_putchar((num / div) + '0');
			num %= div;
			div /= 10;
			c++;
		}
	}
	return (c);
}
