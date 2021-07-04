/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_xX.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:39:09 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/04 14:58:54 by ksoto            ###   ########.fr       */
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
	int	len; /* insertar a la estructura */
	int tmp;
	int	break_flag;
	int counter;

	counter = 0;
	len = 1;
	break_flag = 0;
	tmp = n;
	if (tmp < 0)
		tmp = -tmp;
	len = len_hexadecimal(n, 0);
	str->final_width = str->width > len ? str->width : len;
	str->final_width = str->precision > str->final_width ? str->precision : str->final_width;
	break_flag = print_before(str->final_width, len);
	counter += print_hexadecimal(n);
	print_after(str->final_width, len, break_flag);
	return (counter);
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
	int	len; /* insertar a la estructura */
	int tmp;
	int	break_flag;
	int counter;

	counter = 0;
	len = 1;
	break_flag = 0;
	tmp = n;
	if (tmp < 0)
		tmp = -tmp;
	len = len_hexadecimal(n, 0);
	str->final_width = str->width > len ? str->width : len;
	str->final_width = str->precision > str->final_width ? str->precision : str->final_width;
	break_flag = print_before(str->final_width, len);
	counter += print_HEXADECIMAL(n);
	print_after(str->final_width, len, break_flag);
	return (counter);
}
