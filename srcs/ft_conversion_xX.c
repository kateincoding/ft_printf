/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_xX.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:39:09 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/08 19:10:16 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * len_hexadecimal - Converts decimal to uppercase hexadecimal
 * @n: The number to be converted
 *
 * Return: The number of digits printed
 */
int	len_hexadecimal(unsigned int n, unsigned int counter)
{
	if (n < 16)
		return (counter + 1);
	counter += len_hexadecimal(n / 16, counter);
	return (counter + 1);
}

/**
 * print_hexadecimal - Converts decimal to uppercase hexadecimal
 * @n: The number to be converted
 *
 * Return: The number of digits printed
 */
int	print_hexadecimal(unsigned int n)
{
	int			counter;
	const char	hex_digits[] = "0123456789abcdef";

	counter = 0;
	if (n >= 16)
		counter += print_hexadecimal(n / 16);
	counter += ft_putchar(hex_digits[n % 16]);
	return (counter);
}

/**
 * print_HEXADECIMAL - Converts decimal to uppercase hexadecimal
 * @n: The number to be converted
 *
 * Return: The number of digits printed
 */
int	print_upper_hexa(unsigned int n)
{
	int			counter;
	const char	hex_digits[] = "0123456789ABCDEF";

	counter = 0;
	if (n >= 16)
	{
		counter += print_upper_hexa(n / 16);
	}
	counter += write(1, &hex_digits[n % 16], 1);
	return (counter);
}

/**
 * print_hex - Converts decimal to uppercase hexadecimal
 * @lista: The number of list to be converted
 *
 * Return: The number of digits printed
 */
int	print_hex(va_list lista)
{
	unsigned int	n;
	int				tmp;
	int				counter;

	n = va_arg(lista, int);
	counter = 0;
	str->len = 1;
	str->break_flag = 0;
	tmp = n;
	if (tmp < 0)
		tmp = -tmp;
	str->len = len_hexadecimal(n, 0);
	calculate_format_width();
	str->break_flag = print_before();
	counter += print_hexadecimal(n);
	print_after();
	return (counter);
}

/**
 * print_HEX - Converts decimal to uppercase hexadecimal
 * @lista: The number of list to be converted
 *
 * Return: The number of digits printed
 */
int	print_upper_hexadecimal(va_list lista)
{
	unsigned int	n;
	int				tmp;
	int				counter;

	n = va_arg(lista, int);
	counter = 0;
	str->len = 1;
	str->break_flag = 0;
	tmp = n;
	if (tmp < 0)
		tmp = -tmp;
	str->len = len_hexadecimal(n, 0);
	calculate_format_width();
	str->break_flag = print_before();
	counter += print_upper_hexa(n);
	print_after();
	return (counter);
}
