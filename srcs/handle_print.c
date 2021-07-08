/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 00:01:26 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/08 11:37:54 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** calculate the width of format to handle %u
*/

void	calculate_format_width(void)
{
	str->final_width = str->len;
	if (str->width > str->len)
		str->final_width = str->width;
	if (str->precision > str->final_width)
		str->final_width = str->precision;
}

/*
** print_before: handle the characters that will print before format
*/

int	print_before(void)
{
	int	i;
	int	space;

	str->break_flag = 0;
	if (str->space > 0 && (str->op == 'd' || str->op == 'i'))
	{
		i = 0;
		if (i < str->space)
		{
			str->lenght += ft_putchar_fd(' ', str->fd);
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
		else
			space = str->len;
		while (i < (str->final_width - space))
			str->lenght += ft_putchar_fd(' ', str->fd), i++;
	}
	if (str->op == 'p')
	{
		ft_putchar_fd('0', str->fd);
		ft_putchar_fd('x', str->fd);
	}
	if (str->precision >= 0 && str->final_width != str->len)
	{
		i = 0;
		while (i < str->precision - str->len && str->precision > 0)
		{
			str->lenght += ft_putchar_fd('0', str->fd);
			str->break_flag = 1, i++;
		}
	}
	return (str->break_flag);
}

void	print_after(void)
{
	int	i;
	int	space;

	if (str->precision > str->len)
		space = str->precision;
	else
		space = str->len;
	if (str->minus != 0 && str->final_width != str->len)
	{
		i = 0;
		while (i < (str->final_width - space))
		{
			str->lenght += ft_putchar_fd(' ', str->fd);
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
