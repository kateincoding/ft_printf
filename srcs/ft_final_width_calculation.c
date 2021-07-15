/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_width_calculation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 00:01:26 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/15 06:59:49 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** initialize some variables each time a conversion operator function is called
*/

void	initialize_var_operators(t_fields *str)
{
	str->break_flag = 0;
	str->counter = 0;
	str->null_flag = 0;
	str->positive = 0;
	str->len = 0;
	str->zero_value = 0;
	str->negative = 0;
}

/*
** changing width with special cases "*" "0" "negative *"
*/

void	add_more_width(t_fields *str)
{
	if (str->precision >= 1 && str->minus_precision == 0 && str->negative == 1 && (str->op == 'd' || str->op == 'i'))
		str->final_width++;
	else if (str->minus_precision == 1  && str->negative != 1 && (str->op == 'd' || str->op == 'i'))
		str->final_width--; /* handle width negative */
	else if (str->negative == 1 && str->op == 'u') /*corregir caso linea 343 */
		str->final_width--; /* skipped */
	else if (str->minus_precision == 1 && str->zero_value == 0 && str->op == 'u')
		str->final_width--;
}

/*
** calculate the width of format to handle %u
*/

void	calculate_format_width(t_fields *str)
{
	str->final_width = str->len;
	if (str->width > str->len)
		str->final_width = str->width;
	if (str->precision > str->final_width && str->minus_precision == 0)
		str->final_width = str->precision;
	add_more_width(str);
}
