/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_diu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 05:39:10 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/20 23:15:36 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** calculate integer len
*/

void	calculate_un_len(t_fields *str, int num)
{
	int	tmp;

	tmp = num;
	if (tmp < 0)
	{
		while (tmp < -10)
		{
			tmp = tmp / 10;
			str->len++;
		}
		if (tmp > -10)
			str->len += 1;
	}
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		str->len++;
	}
	if (tmp < 10 && tmp >= 0)
		str->len += 1;
	if (str->zero_value && str->precision == 0)
		str->len = 0;
}

void	calculate_int_len(t_fields *str, int num)
{
	int	tmp;

	tmp = num;
	if (tmp < 0)
	{
		while (tmp <= -10)
		{
			tmp = tmp / 10;
			str->len++;
		}
		if (tmp > -10)
			str->len += 2;
		return ;
	}
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		str->len++;
	}
	if (tmp < 10 && tmp >= 0)
		str->len += 1;
	if (str->zero_value && str->precision == 0)
		str->len = 0;
}

int	putnbr_di(long n, int fd)
{
	int	counter;

	counter = 0;
	if (n == -2147483648)
		counter += ft_putstr_fd("2147483648", fd);
	else if (n < 0)
		counter += putnbr_di(-n, fd);
	else if (n >= 10)
	{
		counter += putnbr_di(n / 10, fd);
		counter += ft_putchar_fd(n % 10 + '0', fd);
	}
	else if (n < 10)
		counter += ft_putchar_fd(n + '0', fd);
	return (counter);
}

/*
** print_int - It will print integers
** @lista: the main string passed to the function
** Return: An integer
*/

int	print_int(t_fields *str, va_list lista)
{
	int	n;

	initialize_var_operators(str);
	n = va_arg(lista, int);
	if (n > 0)
		str->positive = 1;
	else if (n == 0)
		str->zero_value = 1;
	else
		str->negative = 1;
	calculate_int_len(str, n);
	calculate_format_width_d(str);
	print_before_diu(str);
	if (str->zero_value == 1 && str->precision == 0)
		;
	else if (str->negative == 1)
		str->counter += putnbr_di((long)n, str->fd);
	else
		str->counter += putnbr_di((long)n, str->fd);
	print_after_diu(str);
	return (str->counter);
}

/*
** print_unsigned - Convert a number into an unsigned int and print it
** @lista: The number to be converted
**
** Return: The number of digits printed
*/

int	print_unsigned(t_fields *str, va_list lista)
{
	unsigned int	num;
	int				n;

	initialize_var_operators(str);
	num = va_arg(lista, int);
	n = (int)num;
	if (n > 0)
		str->positive = 1;
	else if (n == 0)
		str->zero_value = 1;
	else
		str->negative = 1;
	calculate_un_len(str, num);
	calculate_format_width(str);
	print_before_diu(str);
	if (str->zero_value == 1 && str->precision >= 0)
		;
	else
		str->counter += putnbr_di((long)num, str->fd);
	print_after_diu(str);
	return (str->counter);
}
