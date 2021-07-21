/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:54:49 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/15 06:40:40 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print_space - part of valid_operator_with_flag 
** handle the " " in special cases when there are a " "
** after "." and before a conversion operator "csdiuxXp"
** line 37: checar si es +1 o counter 
*/

int	print_space(t_fields *str)
{
	int	counter;

	counter = 0;
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
	str->idx += counter;
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
		counter += print_space(str);
	else if (validate_operator(str->format[str->idx]))
	{
		str->op = str->format[str->idx];
		counter += select_function(str, args);
		str->idx += 1;
	}
	return (counter);
}
