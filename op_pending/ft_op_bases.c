/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_bases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:39:09 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/08 09:55:04 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * print_octal - Converts a decimal num passed to the argument to an octal
 * num
 * @lista: The num to be converted
 * Return: c of digit in octal num
 */
int print_octal(va_list lista)
{
	unsigned int num, c = 0, index = 0;
	int arr[100];

	num = va_arg(lista, int);
	if (num < 9)
	{
		ft_putchar(num + '0');
		c = 1;
	}
	else if (num >= 9)
	{
		while (num > 0)
		{
			arr[index] = num % 8;
			num /= 8;
			index++;
		}
	}
	while (index--)
	{
		ft_putchar(arr[index] + '0');
		c++;
	}
	return (c);
}

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
 * print_upper_hexa - Converts decimal to uppercase hexadecimal
 * @n: The number to be converted
 *
 * Return: The number of digits printed
 */
int	print_upper_hexa(unsigned int n)
{
	int counter = 0;
	char hex_digits[] = "0123456789ABCDEF";

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

	return (print_upper_hexa(n));
}
