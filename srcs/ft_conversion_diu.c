/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_diu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 05:39:10 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/03 19:17:22 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_before(int width, int len)
{
	int	break_flag = 0;
	int	i;

	if (str->space > 0 && width == len && str->op != 'u')
	{
		// printf("\nhere 1\n");
		i = 0;
		if (i < str->space)
		{
			str->lenght += ft_putchar_fd(' ', str->fd);
			while (i < str->space)
				i++;
		}
	}
	if (str->minus == 0 && width != len && str->precision <= 0)
	{
		// printf("\nhere 2\n");
		i = 0;
		while (i < (width - len))
		{
			str->lenght += ft_putchar_fd(' ', str->fd);
			i++;
		}
	}
	// printf("precision = %d\n", str->precision);
	// printf("width = %d\n", width);
	if (str->precision >= 0 && width != len)
	{
		// printf("\nhere 3\n");
		i = 0;
		while (i < width - len && str->precision > 0)
		{
			str->lenght += ft_putchar_fd('0', str->fd);
			break_flag = 1;
			i++;
		}
	}
	return(break_flag);
}

void	print_after(int width, int len, int break_flag)
{
	int i;

	if (str->minus != 0 && width != len)
	{
		i = 0;
		while(i < (width - len))
		{
			if (break_flag == 1)
			{
				break;
			}
			str->lenght += ft_putchar_fd(' ', str->fd);
			i++;
		}
	}
}


int print_body(int c, int n)
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


/**
*print_int - It will print integers
*@lista: the main string passed to the function
*Return: An integer
*/
int	print_int(va_list lista)
{
	int	n;
	int	c = 0;
	int	width;
	int	len = 1;
	int	tmp;
	int	break_flag = 0;

	n = va_arg(lista, int);
	tmp = n;
	if (tmp < 0)
		tmp = -tmp;
	while(tmp > 10)
	{
		tmp = tmp/10;
		len++;
	}
	/* handle flags , also needs to see precision*/
	width = str->width > len ? str->width : len;
	width = str->precision > width ? str->precision : width;
	break_flag = print_before(width, len);
	/* printing number */
	c = print_body(c, n);
	print_after(width, len, break_flag);
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
	unsigned int num;
	unsigned int c = 0;
	unsigned div;
	int	width;
	int	len = 1;
	int tmp;
	int	break_flag = 0;

	num = va_arg(lista, int);
	tmp = num;
	if (tmp < 0)
		tmp = -tmp;
	while(tmp > 10)
	{
		tmp = tmp/10;
		len++;
	}
	/* handle flags , also needs to see precision*/
	width = str->width > len ? str->width : len;
	width = str->precision > width ? str->precision : width;
	break_flag = print_before(width, len);

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
	print_after(width, len, break_flag);
	return (c);
}
