/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 00:01:26 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/10 15:57:44 by ksoto            ###   ########.fr       */
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
//	printf("\n===final len = %d ===\n", str->len);
//	printf("===final width = %d ===\n", str->final_width);
}

void	print_before_before(t_fields *str, int i, int space)
{
	if (str->zero == 0) /* print spaces before */
	{
		if (str->space > 0 && (str->op == 'd' || str->op == 'i'))
		{
			i = 0;
	//		printf("\n ====== here hey =====\n");
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
	/* print sign */
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
//	printf("zeros %d\n", str->precision);
/* print zero */
	if ((str->zero != 0 || str->precision > 0) && str->final_width != str->len)
	{
		// printf ("\n=====hereeeeee\n");
		i = 0;
		zeros = 0;
		if (str->precision != 0 && str->zero_value == 1)
			zeros = str->final_width - str->len - str->counter;
		else
			zeros = str->final_width - str->len - str->counter;
//		printf("final width %d\n", str->final_width);
		// printf("width %d\n", str->width);
//		printf("final len %d\n", str->len);
		// printf("final counter %d\n", str->counter);
//		printf("zeros %d\n", zeros);
		while (i < zeros)
		{
//			printf("\n hey1 \n");
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
	if (str->zero == 0 && str->minus != 0 && str->final_width != str->len)
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
