/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags_structure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 05:15:04 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/15 06:53:52 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** restart_flags - re-initializate the structure each time a %operator is called
** str: structure of the flags and other variables
** it will added in the funciton of file handle_format.c
*/

void	restart_flags(t_fields *str)
{
	str->minus = 0;
	str->minus_precision = 0;
	str->zero = 0;
	str->width = 0;
	str->final_width = 0;
	str->wildcard = 0;
	str->precision = -1;
	str->space = 0;
	str->len = 0;
	str->lenght = 0;
	str->break_flag = 0;
	str->plus = 0;
}

/*
** valid_operator_with_flag - validate  "-0.*# +"
** %[$][flags][width][.precision][length modifier]conversion
** %[$][flags][0 - 9][. + [0-9]][length modifier]conversion
*/

void	set_flags(t_fields *str)
{
	int	i;

	i = str->idx;
	while (validate_only_flag(str->format[i]))
	{
		if (str->format[i] == '-')
			str->minus += 1;
		if (str->format[i] == '0')
			str->zero += 1;
		if (str->format[i] == '#')
			str->hashtag += 1;
		if (str->format[i] == ' ')
			str->space += 1;
		if (str->format[i] == '+')
			str->plus += 1;
		i++;
	}
	str->idx = i;
}

void	set_width(t_fields *str, va_list args_list)
{
	int	i;
	int	n;

	i = str->idx;
	n = 0;
	if (str->format[i] == '*')
	{
		n = va_arg(args_list, int);
		if (n < 0)
		{
			str->minus = 1;
			n = -1 * n;
		}
		i++;
	}
	while ('0' <= str->format[i] && str->format[i] <= '9')
		n = 10 * n + str->format[i] - '0', i++;
	str->width = n;
	str->idx = i;
}

/*
** check if predomine * or number and change the order to assign n value
*/

void	set_precision(t_fields *str, va_list args_list)
{
	int	i;
	int	n;

	i = str->idx;
	n = 0;
	if (str->format[i] == '.')
	{
		i++;
		while ('0' <= str->format[i] && str->format[i] <= '9')
			n = 10 * n + str->format[i] - '0', i++;
		if (str->format[i] == '*')
		{
			n = va_arg(args_list, int);
			if (n < 0)
			{
				str->minus_precision = 1;
				n = -1 * n;
			}
			i++;
		}
		str->precision = n;
		str->idx = i;
	}
}
