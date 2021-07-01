/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:54:49 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/01 05:06:35 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** valid_operator_with_flag - validate
** %[$][flags][width][.precision][length modifier]conversion
** %[$][flags][0 - 9][. + [0-9]][length modifier]conversion
*/
int print_format(va_list args)
{
	int counter = 0;

	restart_flags();
	set_flags();
	set_width(args);
	set_precision(args);
	if (str->format[str->idx] == ' ')
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
	}
	else if (validate_operator(str->format[str->idx]))
	{
		str->op = str->format[str->idx];
		// printf("sending to execute the modifyer operator\n");
		counter += select_function(args);
		str->idx += 1;
		// printf("operator = %c\n", str->format[i]);
	}
	str->lenght += counter;
	return(10);
}


void restart_flags(void)
{
	str->minus = 0;
	str->zero = 0;
	str->width = 0;
	str->wildcard = 0;
	str->precision = -1;
	str->space = 0;
}

/*
** valid_operator_with_flag - validate
** %[$][flags][width][.precision][length modifier]conversion
** %[$][flags][0 - 9][. + [0-9]][length modifier]conversion
*/

void set_flags(void)
{
	int i = str->idx;

	// "-0.*# +"
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
	// printf("\n idx %d\n", str->idx);
}

void set_width(va_list args_list)
{
	int i = str->idx;
	int n = 0;

	// [0-9] || *
	while ('0' <= str->format[i] && str->format[i] <= '9')
		n = 10 * n + str->format[i] - '0', i++;
	if (str->format[i] == '*')
		n = va_arg(args_list, int), i++;
	str->width = n;
	str->idx = i;
	// printf("\n idx %d\n", str->idx);
}

/* check if predomine * or number and change the order to assign n value */
void set_precision(va_list args_list)
{
	int i = str->idx;
	int n = 0;

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
	// printf("\n idx %d\n", str->idx);
}
