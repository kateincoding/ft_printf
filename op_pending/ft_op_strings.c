/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:38:49 by ksoto             #+#    #+#             */
/*   Updated: 2021/06/22 22:38:53 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
*print_char - print a char at printf
*@lista: the main string passed to the function
*Return: An integer
*/
int print_char(va_list lista)
{
	/*va_arg (va_list ap, type)*/
	ft_putchar(va_arg(lista, int));
	return (1);
	/* returning true */
}

/**
*print_str - print a char at printf
*@lista: the main string passed to the function
*Return: An integer
*/
int print_str(va_list lista)
{
	unsigned int count = 0;

	char *str = va_arg(lista, char *);

	if (!str || str == NULL)
	{
		ft_putchar('(');
		ft_putchar('n');
		ft_putchar('u');
		ft_putchar('l');
		ft_putchar('l');
		ft_putchar(')');
		return (6);
	}
	while (*str)
	{
		write(1, &(*str++), 1);
		count++;
	}
	return (count);
}

/**
*print_rev_str - function that prints the reverse of the string
*@lista: args of printf to print
*Return: numbers of char printed
*/
int print_rev_str(va_list lista)
{
	int length;
	char *s = va_arg(lista, char *);

	if (!s)
		s = ")Null(";

	length = ft_strlen(s);
	while (--length >= 0)
		write(1, &s[length], 1);
	length = ft_strlen(s);
	return (length);
}

/**
* print_Str_Ascii - Print a string
* @arg: String address
* Return: integer
*/
int print_Str_Ascii(va_list arg)
{
	char *s = va_arg(arg, char *);
	int c, i = 0;

	if (s == NULL)
		s = "(null)";

	for (c = 0; s[c]; c++)
	{
		if (s[c] < 32 || s[c] >= 127)
		{
			ft_putchar('\\');
			ft_putchar('x');
			print_HEXADECIMAL(s[c] / 16);
			print_HEXADECIMAL(s[c] % 16);
			i += 4;
		}
		else
		{
			ft_putchar(s[c]);
			i++;
		}
	}
	return (i);
}
