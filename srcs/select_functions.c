/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:38:40 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/07 15:49:06 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * select_function - structured list to work with it
 * @format: string with operators
 * @list: list of arguments to print
 * Return: numbers of char printed
 */
int	select_function(va_list args)
{
	unsigned int	i;
	unsigned int	result;

	i = 0;
	result = 0;
	if (!str->format[i])
		return (-1);
	t_func 	operator[] = {
			{'c', print_char},
			{'s', print_str},
			{'d', print_int},
			{'i', print_int},
			{'u', print_unsigned},
			{'x', print_hex},
			{'X', print_HEX},
			{'p', print_ptr},
			{'\0', NULL}};

	// printf("\ntst here %c\n", str->op);
	while (operator[i].op)
	{
		// printf("\ntst here %c\n", str->op);
		if (str->op == operator[i].op)
		{
			// printf("\nhere\n");
			result += operator[i].f(args);
			break;
		}
		i++;
	}
	if (result == 0)
		return (0);
	return (result);
}
