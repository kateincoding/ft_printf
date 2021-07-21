/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_cs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 05:23:04 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/20 12:20:36 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** calculate the width of format to handle %u
** changing width with special cases "*" "0" "negative *"
*/

void	calculate_format_width_s(t_fields *str, char *av)
{
	str->final_width = str->len;
	if (str->precision < str->len && str->precision != -1)
	{
		str->len = str->precision;
		str->final_width = str->len;
	}
	if (!av && str->precision > 0)
	{
		if (str->precision <= 6)
			str->len = str->precision;
		else
			str->len = 6;
		str->final_width = str->len;
	}
	if (str->width > str->len)
		str->final_width = str->width;
}

/*
** print_char - print a char at printf
** @lista: the main string passed to the function
** Return: An integer
*/

int	print_char(t_fields *str, va_list lista)
{
	char	c;

	c = va_arg(lista, int);
	initialize_var_operators(str);
	str->len = 1;
	calculate_format_width(str);
	print_before_cs(str);
	str->counter = ft_putchar_fd(c, str->fd);
	print_after_cs(str);
	return (str->counter);
}

/*
** part 2 of print_str -> print (null)
*/

int	print_null(t_fields *str, char *av)
{
	if (!av && (str->precision == -1 || str->minus_precision == 1))
	{
		str->counter += write(str->fd, "(null)", 6);
		return (1);
	}
	else if (!av && str->precision > 0)
	{
		if (str->precision <= 6)
			str->counter += write(str->fd, "(null)", str->precision);
		else
			str->counter += write(str->fd, "(null)", 6);
	}
	return (0);
}

/*
** print_str - print a char at printf
** @lista: the main string passed to the function
** Return: An integer
*/

int	print_str(t_fields *str, va_list lista)
{
	char			*av;
	int				i;

	i = 0;
	av = va_arg(lista, char *);
	initialize_var_operators(str);
	if (av)
		str->len = ft_strlen(av);
	else
		str->len = 0;
	calculate_format_width_s(str, av);
	print_before_cs(str);
	if (print_null(str, av) == 1)
		return (str->counter);
	while (av && *av && i < str->len)
	{
		str->counter += write(str->fd, &(*av++), 1);
		i++;
	}
	print_after_cs(str);
	return (str->counter);
}
