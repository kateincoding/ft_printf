/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_xX.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:39:09 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/15 06:13:09 by ksoto            ###   ########.fr       */
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
 * print_upper_hexa - Converts decimal to uppercase hexadecimal
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
int	print_hex(t_fields *str, va_list lista)
{
	unsigned int	n;
	int				tmp;

	initialize_var_operators(str);
	n = va_arg(lista, int);
	str->len = 1;
	tmp = n;
	if (tmp < 0)
		tmp = -tmp;
	str->len = len_hexadecimal(n, 0);
	calculate_format_width(str);
	print_before_x(str);
	str->counter += print_hexadecimal(n);
	print_after_x(str);
	return (str->counter);
}

/**
 * print_upper_hexadecimal - Converts decimal to uppercase hexadecimal
 * @lista: The number of list to be converted
 *
 * Return: The number of digits printed
 */
int	print_upper_hexadecimal(t_fields *str, va_list lista)
{
	unsigned int	n;
	int				tmp;

	initialize_var_operators(str);
	n = va_arg(lista, int);
	str->len = 1;
	tmp = n;
	if (tmp < 0)
		tmp = -tmp;
	str->len = len_hexadecimal(n, 0);
	calculate_format_width(str);
	print_before_x(str);
	str->counter += print_upper_hexa(n);
	print_after_x(str);
	return (str->counter);
}
