/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 19:36:06 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/20 19:40:18 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** is_mac_behaviour - Simulates the behaviour of mac in error cases
** @str: str
** @format: Format to print to the console
** Return: number of char printed
*/

int	is_mac_behaviour(t_fields *str, const char *format,
						unsigned int *i, int result)
{
	int	tmp;

	while (format[*i] == ' ')
		(*i)++;
	if ('0' <= format[*i] && format[*i] <= '9')
	{
		tmp = format[*i] - '0';
		while (tmp > 1)
			result += ft_putchar_fd(' ', str->fd), tmp--;
		(*i)++;
	}
	if (format[*i] == '.')
	{
		(*i)++;
		while ('0' <= format[*i] && format[*i] <= '9')
			(*i)++;
	}
	result += ft_putchar_fd(format[*i], str->fd);
	return (result);
}

int	valid_token(t_fields *str, const char *format, unsigned int *i, int result)
{
	if (IS_MACOS == 1)
		result += is_mac_behaviour(str, format, i, 0);
	if (IS_MACOS == 0)
	{
		result += ft_putchar_fd('%', str->fd);
		if (format[*i] == ' ')
			result += ft_putchar_fd(' ', str->fd), (*i)++;
		while (format[*i] == ' ')
			(*i)++;
		result += ft_putchar_fd(format[*i], str->fd);
	}
	return (result);
}

int	token(t_fields *str, const char *format, unsigned int *i, va_list args)
{
	int	result;

	result = 0;
	(*i)++;
	if (format[*i] == '\0')
		return (-1);
	str->idx = *i;
	if (format[*i] == '%')
		result += ft_putchar_fd(format[*i], str->fd);
	else if (valid_operator_flag_modifier(format, *i) == 0)
		result += valid_token(str, format, i, 0);
	else
	{
		result += print_format(str, args);
		str->idx--;
		*i = str->idx;
	}
	return (result);
}

/*
** ft_vfprintf - Simulates the printf function
** @format: Format to print to the console
** Return: number of char printed
*/

int	ft_vfprintf(int fd, const char *format, va_list args)
{
	unsigned int	i;
	unsigned int	result;
	t_fields		*str;

	result = 0;
	i = 0;
	if (format == NULL)
		return (-1);
	str = (t_fields *)ft_memalloc(sizeof(t_fields));
	initialize_stack(str, format, fd);
	while (format && format[i] && i < ft_strlen(format))
	{
		while (format[i] != '%' && format[i])
		{
			result += ft_putchar_fd(format[i], fd);
			i++;
		}
		str->idx = i;
		if (format[i] == '%' && format[i])
			result += token(str, format, &i, args);
		i++;
	}
	finalize_stack(str);
	return (result);
}
