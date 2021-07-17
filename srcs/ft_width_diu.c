/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_diu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 21:58:12 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/16 22:07:01 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

/*
** calculate the width of format to handle %u
** changing width with special cases "*" "0" "negative *"
*/

void	calculate_format_width_d(t_fields *str)
{
	str->final_width = str->len;
	if (str->width > str->len)
		str->final_width = str->width;
	if (str->precision > str->final_width && str->minus_precision == 0)
		str->final_width = str->precision;
	if (str->precision >= 1 && str->minus_precision == 0 && str->negative == 1 && (str->op == 'd' || str->op == 'i'))
		str->final_width++;
	else if (str->minus_precision == 1  && str->negative != 1 && (str->op == 'd' || str->op == 'i'))
		str->final_width--; /* handle width negative */
}

/*
void	calculate_format_width(t_fields *str)
{
	str->final_width = str->len;
	if (str->width > str->len)
		str->final_width = str->width;
	if (str->precision > str->final_width && str->minus_precision == 0)
		str->final_width = str->precision;
	if (str->precision >= 1 && str->minus_precision == 0 && str->negative == 1 && (str->op == 'd' || str->op == 'i'))
		str->final_width++;
	else if (str->minus_precision == 1  && str->negative != 1 && (str->op == 'd' || str->op == 'i'))
		str->final_width--;
	else if (str->negative == 1 && str->op == 'u') 
		str->final_width--;
	else if (str->minus_precision == 1 && str->zero_value == 0 && str->op == 'u')
		str->final_width--;
}
*/