/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:38:40 by ksoto             #+#    #+#             */
/*   Updated: 2021/06/28 13:56:20 by ksoto            ###   ########.fr       */
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
 * select_function - structured list to work with it
 * @format: string with operators
 * @list: list of arguments to print
 * Return: numbers of char printed
 */
int select_function(t_fields *str, va_list args)
{
	unsigned int i = str->idx, result = 0;

	if (!str->format[i])
		return (-1);

	/* falta p & f */
	t_func 	operator[] = {
			{'c', print_char},
			{'s', print_str},
	/*		{'d', print_int},
			{'i', print_int},
			{'u', print_unsigned},*/
	//		{'o', print_octal},
	/*		{'x', print_hex},
			{'X', print_HEX},*/
	//		{'b', print_bin},
	//		{'S', print_Str_Ascii},
	//		{'r', print_rev_str},
	//		{'R', print_rot13},
			{'\0', NULL}};

	while (operator[i].op)
	{
		if (str->op == operator[i].op)
		{
			printf("here %c\n", operator[i].op);
            result += operator[i].f(args);
			break;
		}
		i++;
	}
	if (result == 0)
		return (0);
	return (result);
}
