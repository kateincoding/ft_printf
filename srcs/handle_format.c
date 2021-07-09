/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:54:49 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/08 20:18:20 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_space(t_fields *str, int counter)
{
	counter += ft_putchar_fd('%', str->fd);
	if (str->space != 0)
		counter += ft_putchar_fd(' ', str->fd);
	if (str->width != 0)
		counter += ft_putnbr_fd(str->width, str->fd);
	if (str->precision != 0)
	{
		counter += ft_putchar_fd('.', str->fd);
		counter += ft_putnbr_fd(str->precision, str->fd);
	}
	str->idx += counter; /* checar si es +1 o counter */
	return (counter);
}

/*
** valid_operator_with_flag - validate
** %[$][flags][width][.precision][length modifier]conversion
** %[$][flags][0 - 9][. + [0-9]][length modifier]conversion
*/
int	print_format(t_fields *str, va_list args)
{
	int	counter;

	counter = 0;
	restart_flags(str);
	set_flags(str);
	set_width(str, args);
	set_precision(str, args);
	if (str->format[str->idx] == ' ')
		counter = print_space(str, counter);
	else if (validate_operator(str->format[str->idx]))
	{
		str->op = str->format[str->idx];
		counter += select_function(str, args);
		str->idx += 1;
	}
	str->lenght += counter;
	return (10);
}

void	restart_flags(t_fields *str)
{
	str->minus = 0;
	str->zero = 0;
	str->width = 0;
	str->final_width = 0;
	str->wildcard = 0;
	str->precision = -1;
	str->space = 0;
	str->len = 0;
	str->break_flag = 0;
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
	while ('0' <= str->format[i] && str->format[i] <= '9')
		n = 10 * n + str->format[i] - '0', i++;
	if (str->format[i] == '*')
		n = va_arg(args_list, int), i++;
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
			n = va_arg(args_list, int), i++;
		str->precision = n;
		str->idx = i;
	}
}
