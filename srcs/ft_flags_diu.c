/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_diu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 06:15:36 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/15 06:57:21 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print_before_before_diu: handle the spaces " " and signs "+", "-"
*/

void	print_before_before_diu(t_fields *str, int i, int space)
{
	if (str->zero == 0)
	{
		if (str->space > 0 && (str->op == 'd' || str->op == 'i'))
		{
			i = 0;
			if (i < str->space)
			{
				str->counter += ft_putchar_fd(' ', str->fd);
				while (i < str->space)
					i++;
				str->final_width--;
			}
		}
		if (str->minus == 0)
		{
			i = 0;
			if (str->precision > str->len)
				space = str->precision;
			else if (str->zero_value == 1 && str->final_width >= 1 && str->precision != 0)
				space = 1;
			else
				space = str->len;
			while (i < (str->final_width - space - (str->negative == 1)))
				str->counter += ft_putchar_fd(' ', str->fd), i++;
		}
	}
	if (str->plus == 1 && str->positive == 1)
		str->counter += ft_putchar_fd('+', str->fd);
	if (str->negative == 1 && (str->op == 'd' || str->op == 'i'))
		str->counter += ft_putchar_fd('-', str->fd);
}

/*
** print_before: handle the characters "0" that will print before format
*/

void	print_before_diu(t_fields *str)
{
	int	i;
	int zeros;

	print_before_before_diu(str, 0, 0);
	if (str->zero != 0 || str->precision > 0)
	{
		i = 0;
		zeros = 0;
		if (str->precision != 0 && str->zero_value == 1)
			zeros = str->final_width - str->len - str->counter;
		else
			zeros = str->final_width - str->len - str->counter;
		while (i < zeros && !(str->zero > 0 && str->minus == 1))
		{
			str->counter += ft_putchar_fd('0', str->fd);
			str->break_flag = 1;
			i++;
		}
		while (i < zeros && str->precision != 0)
		{
			str->counter += ft_putchar_fd('0', str->fd);
			str->break_flag = 1;
			i++;
		}
	}
}

/*
** print_after: handle the spaces " "
*/

void	print_after_diu(t_fields *str)
{
	int	i;
	int	space;

	space = str->counter;
	if (str->minus != 0 && str->final_width != str->len)
	{
		i = 0;
		while ((i < (str->final_width - space)) && str->zero == 0)
		{
			str->counter += ft_putchar_fd(' ', str->fd);
			i++;
		}
		while ((i < (str->final_width - space)) && str->zero > 0)
		{
			str->counter += ft_putchar_fd(' ', str->fd);
			i++;
		}
	}
	else if (str->final_width != str->len && str->break_flag == 1)
	{
		i = -1;
	}
}
