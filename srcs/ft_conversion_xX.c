/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_xX.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:39:09 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/01 05:58:03 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * print_hexadecimal - Converts decimal to uppercase hexadecimal
 * @n: The number to be converted
 *
 * Return: The number of digits printed
 */
int	print_hexadecimal(unsigned int n)
{
	int counter = 0;
	char hex_digits[] = "0123456789abcdef";

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
int	print_HEXADECIMAL(unsigned int n)
{
	int counter = 0;
	char hex_digits[] = "0123456789ABCDEF";

	if (n >= 16)
	{
		counter += print_HEXADECIMAL(n / 16);
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
int print_hex(va_list lista)
{
	unsigned int n = va_arg(lista, int);

	return (print_hexadecimal(n));
}

/**
 * print_HEX - Converts decimal to uppercase hexadecimal
 * @lista: The number of list to be converted
 *
 * Return: The number of digits printed
 */
int print_HEX(va_list lista)
{
	unsigned int n = va_arg(lista, int);

	return (print_HEXADECIMAL(n));
}
