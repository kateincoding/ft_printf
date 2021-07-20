/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:52:02 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/20 21:45:30 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print_before_before_p: handle the spaces " " and signs "+", "-"
*/

void	print_before_before_p(t_fields *str, int i, int space)
{
	if (str->zero == 0)
	{
		if (str->minus == 0)
		{
			i = 0;
			if (str->precision > str->len)
				space = str->precision;
			else if (str->zero_value == 1 && str->final_width >= 1
				&& str->precision != 0)
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
** print_before_p: handle the characters "0" that will print before format
*/

void	print_before_p(t_fields *str)
{
	int	i;
	int	zeros;

	print_before_before_p(str, 0, 0);
	if (str->op == 'p')
	{
		str->counter += ft_putchar_fd('0', str->fd);
		str->counter += ft_putchar_fd('x', str->fd);
	}
	if (str->op == 'p' && str->null_flag == 1 && str->break_flag == 1)
		str->counter += write(str->fd, "000", 3);
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
** print_after_p: handle the spaces " "
*/

void	print_after_p(t_fields *str)
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
