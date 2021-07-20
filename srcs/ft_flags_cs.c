/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:51:55 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/20 18:44:41 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print_before_before_cs: handle the spaces " " for char or string
*/

void	print_before_before_cs(t_fields *str, int i, int space)
{
	if (str->zero == 0)
	{
		if (str->minus == 0)
		{
			i = 0;
			if (str->precision > str->len)
				space = str->precision;
			else if (str->zero_value == 1 && \
					str->final_width >= 1 && str->precision != 0)
				space = 1;
			else
				space = str->len;
			while (i < (str->final_width - space - (str->negative == 1)))
				str->counter += ft_putchar_fd(' ', str->fd), i++;
		}
	}
}

/*
** print_before_cs: handle the characters "0" that will print before format
*/

void	print_before_cs(t_fields *str)
{
	int	i;
	int	zeros;

	print_before_before_cs(str, 0, 0);
	if (str->minus == 0 && (str->zero != 0 || str->precision > 0))
	{
		i = 0;
		zeros = 0;
		if (str->precision != 0 && str->zero_value == 1)
			zeros = str->final_width - str->len - str->counter;
		else
			zeros = str->final_width - str->len - str->counter;
		while (i < zeros && !(str->zero > 0 && str->minus == 1))
		{
			str->counter += ft_putchar_fd(' ', str->fd);
			str->break_flag = 1;
			i++;
		}
		while (i < zeros && str->precision != 0)
		{
			str->counter += ft_putchar_fd(' ', str->fd);
			str->break_flag = 1;
			i++;
		}
	}
}

/*
** print_after_cs: handle the characters that will print before format
*/

void	print_after_cs(t_fields *str)
{
	int	i;
	int	space;

	space = str->counter;
	if (str->minus != 0 && (str->op == 'c' || str->precision != -1))
	{
		i = 0;
		while ((i < (str->final_width - space)) && str->zero == 0)
			str->counter += ft_putchar_fd(' ', str->fd), i++;
		while ((i < (str->final_width - space)) && str->zero > 0)
			str->counter += ft_putchar_fd(' ', str->fd), i++;
	}
	else if (str->minus != 0 && str->op == 's' && str->precision == -1
		&& (str->final_width > str->counter))
	{
		i = 0;
		while ((i < (str->final_width - space)) && str->zero == 0)
			str->counter += ft_putchar_fd(' ', str->fd), i++;
	}
	else if (str->final_width != str->len && str->break_flag == 1)
		i = -1;
}
