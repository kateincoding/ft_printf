/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 00:01:26 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/07 13:45:15 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** calculate the width of format to handle %u
*/
void calculate_format_width()
{
	str->final_width = str->len;
	if (str->width > str->len)
		str->final_width = str->width;
	if (str->precision > str->final_width)
		str->final_width = str->precision;
}

int	print_before(int width, int len)
{
	int	break_flag;
	int	i;
	int space;
	(void)width;

	break_flag = 0;
	/* case minus */
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
	/* case not minus */
	if (str->minus == 0)
	{
		i = 0;
		if (str->precision > len)
			space = str->precision;
		else
			space = len;
		while (i < (str->final_width - space))
			str->lenght += ft_putchar_fd(' ', str->fd), i++;
	}
	if (str->op == 'p')
	{
		ft_putchar_fd('0', str->fd);
    	ft_putchar_fd('x', str->fd);
	}
	if (str->precision >= 0 && str->final_width != len)
	{
		i = 0;
		while (i < str->precision - len && str->precision > 0)
		{
			str->lenght += ft_putchar_fd('0', str->fd);
			break_flag = 1, i++;
		}
	}
	return (break_flag);
}

void	print_after(int width, int len, int break_flag)
{
	int	i;
	int space;
	(void) width;

	if (str->precision > len)
		space = str->precision;
	else
		space = len;

	if (str->minus != 0 && str->final_width != len)
	{
		i = 0;
		while (i < (str->final_width - space))
		{
			str->lenght += ft_putchar_fd(' ', str->fd);
			i++;
		}
	}
	else if (str->final_width != len && break_flag == 1)
	{
		i = -1;

		// while (++i < (width - space))
		// 	str->lenght += ft_putchar_fd(' ', str->fd);
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
