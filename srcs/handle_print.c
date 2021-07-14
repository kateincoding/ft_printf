/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 00:01:26 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/14 08:57:27 by ksoto            ###   ########.fr       */
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
	str->zero_value = 0;
	str->negative = 0;
}

void add_more_width(t_fields *str)
{
//	printf("here\n");
//	printf("minus precision  %d\n", str->minus_precision);
//	printf("negative  %d\n", str->negative);
//	printf("op  %c\n", str->op);
	if (str->precision >= 1 && str->minus_precision == 0 && str->negative == 1 && (str->op == 'd' || str->op == 'i'))
		str->final_width++;
	else if (str->minus_precision == 1  && str->positive == 1 && str->op == 'd')
		str->final_width--;
	else if ((str->negative == 1 || str->minus_precision == 1) && str->op == 'u') /*corregir caso linea 343 */
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
	if (str->precision > str->final_width)
		str->final_width = str->precision;
	add_more_width(str);
//	printf("\n===final len = %d ===\n", str->len);
//	printf("===final width = %d ===\n", str->final_width);
}

void	print_before_before(t_fields *str, int i, int space)
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
		//			if (str->op == 'p' && str->null_flag == 1)
		//				space = space - 3;
			else if (str->zero_value == 1 && str->final_width >= 1 && str->precision != 0)
				space = 1;
			else
				space = str->len;
			while (i < (str->final_width - space - (str->negative == 1)))
				str->counter += ft_putchar_fd(' ', str->fd), i++;
		}
	}
// print sign
	if (str->plus == 1 && str->positive == 1)
		str->counter += ft_putchar_fd('+', str->fd);
	if (str->negative == 1 && (str->op == 'd' || str->op == 'i'))
		str->counter += ft_putchar_fd('-', str->fd);
}

/*
** print_before: handle the characters that will print before format
*/

void	print_before(t_fields *str)
{
	int	i;
	int zeros;

	print_before_before(str, 0, 0);
	if (str->op == 'p')
	{
		str->counter += ft_putchar_fd('0', str->fd); /* revisar si se le agrega al counter */
		str->counter += ft_putchar_fd('x', str->fd);
	}
	if (str->op == 'p' && str->null_flag == 1 && str->break_flag == 1)
		str->counter += write(str->fd, "000", 3);
// print zero
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
//		printf("zeros  %d\n", zeros);
//		printf("final  %d\n", str->final_width);
//		printf("counter  %d\n", str->counter);
		while (i < zeros && str->precision != 0)
		{
			str->counter += ft_putchar_fd('0', str->fd);
			str->break_flag = 1;
			i++;
		}
	}
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
		space = str->counter;
	space = str->counter; /* test si no fx, borrar */
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
