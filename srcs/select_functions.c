/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:38:40 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/08 22:55:47 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * select_function - structured list to work with it
 * @format: string with operators
 * @list: list of arguments to print
 * Return: numbers of char printed
 */
int	select_function(t_fields *str, va_list args)
{
	unsigned int	i;
	unsigned int	result;
	const t_func	operator[9] = {{'c', print_char}, {'s', print_str},
									{'d', print_int}, {'i', print_int},
									{'u', print_unsigned}, {'x', print_hex},
									{'X', print_upper_hexadecimal},
									{'p', print_ptr}, {'\0', NULL}};

	i = 0;
	result = 0;
	if (!str->format[i])
		return (-1);
	while (operator[i].op)
	{
		if (str->op == operator[i].op)
		{
			result += operator[i].f(str, args);
			break ;
		}
		i++;
	}
	if (result == 0)
		return (0);
	return (result);
}
