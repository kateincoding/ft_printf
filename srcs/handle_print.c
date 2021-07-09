/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 00:01:26 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/09 17:38:05 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_var_operators(t_fields *str)
{
	str->break_flag = 0;
	str->counter = 0;
	str->null_flag = 0;
	str->positive = 0;
	str->len = 0;
}


/*
** calculate the width of format to handle %u
*/

void	calculate_format_width(t_fields *str)
{
	str->final_width = str->len;
	if (str->width > str->len)
		str->final_width = str->width;
	if (str->precision > str->final_width)
		str->final_width = str->precision;
}

void	print_before_before(t_fields *str, int i, int space)
{
	str->break_flag = 0;
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
//			if (str->op == 'p' && str->null_flag == 1)
//				space = space - 3;
		else
			space = str->len;
		while (i < (str->final_width - space))
			str->counter += ft_putchar_fd(' ', str->fd), i++;
	}
	if (str->plus == 1 && str->positive == 1)
		str->counter += ft_putchar_fd('+', str->fd);
}

/*
** print_before: handle the characters that will print before format
*/

void	print_before(t_fields *str)
{
	int	i;

	print_before_before(str, 0, 0);
	if (str->op == 'p')
	{
		str->counter += ft_putchar_fd('0', str->fd); /* revisar si se le agrega al counter */
		str->counter += ft_putchar_fd('x', str->fd);
	}
	if (str->precision >= 0 && str->final_width != str->len)
	{
		i = 0;
		while (i < str->precision - str->len && str->precision > 0)
		{
			str->counter += ft_putchar_fd('0', str->fd);
			str->break_flag = 1;
			i++;
		}
	}
	if (str->op == 'p' && str->null_flag == 1 && str->break_flag == 1)
		str->counter += write(str->fd, "000", 3);
}

void	print_after(t_fields *str)
{
	int	i;
	int	space;

	if (str->precision > str->len)
		space = str->precision;
	else
		space = str->len;
	if (str->op == 'p')
	{
		space = str->counter;
	}
	if (str->minus != 0 && str->final_width != str->len)
	{
		i = 0;
		while (i < (str->final_width - space))
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

/*
void	print_after(int width, int len, int break_flag)
{
	int	i;

	if (str->minus != 0 && width != len)
	{
		i = 0;
		while (i < (width - len))
		{
			if (break_flag == 1)
			{
				// i = 0;
				// while (++i < (width - (str->precision + len)))
				//	str->lenght += ft_putchar_fd(' ', str->fd);
				break;
			}
			str->lenght += ft_putchar_fd(' ', str->fd);
			i++;
		}
	}
}
*/
