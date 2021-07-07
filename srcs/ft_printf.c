/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:35:30 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/07 15:28:07 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**
** _printf - Simulates the printf function
** @format: Format to print to the console
** Return: number of char printed
*/

int	ft_vfprintf(int fd, const char *format, va_list args)
{
	unsigned int	i;
	unsigned int	result;
	int				tmp;

	result = 0;
	tmp = 0;
	i = 0;
	if (format == NULL)
		return (-1);
	initialize_stack(format, fd);
	while (format && format[i] && i < ft_strlen(format))
	{
		while (format[i] != '%' && format[i])
		{
			result += ft_putchar_fd(format[i], fd);
			i++;
		}
		str->idx = i;
		if (format[i] == '%' && format[i])
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			str->idx = i;
			if (format[i] == '%')
				result += ft_putchar_fd(format[i], fd);
			else if (valid_operator_flag_modifier(format, i) == 0)
			{
				if (IS_MACOS == 1)
				{
					while (format[i] == ' ')
						i++;
					if ('0' <= format[i] && format[i] <= '9')
					{
						tmp = format[i] - '0';
						while (tmp > 1)
							result += ft_putchar_fd(' ', fd), tmp--;
						i++;
					}
					result += ft_putchar_fd(format[i], fd);
				}
				if (IS_MACOS == 0)
				{
					result += ft_putchar_fd('%', fd);
					if (format[i] == ' ')
						result += ft_putchar_fd(' ', fd), i++;
					while (format[i] == ' ')
						i++;
					result += ft_putchar_fd(format[i], fd);
				}
			}
			else
			{
				print_format(args);
				str->idx--;
				i = str->idx;
			}
		}
		i++;
	}
	result = str->lenght;
	finalize_stack();
	return (result);
}

/*
**  ft_dprintf - printf with file description
**  @fd: fd where printf prints
**  @format: format of args
*/

int	ft_dprintf(const int fd, const char *format, ...)
{
	va_list	args;
	int		result;

	if (format == NULL)
		return (-1);
	if (format[0] == '%' && format[1] == 0)
		return (0);
	va_start(args, format);
	result = ft_vfprintf(fd, format, args);
	va_end(args);
	return (result);
}

/*
**  ft_printf - replicates printf
**  @format: format of args
*/

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;

	if (format == NULL)
		return (-1);
	if (format[0] == '%' && format[1] == 0)
		return (0);
	va_start(args, format);
	result = ft_vfprintf(1, format, args);
	va_end(args);
	return (result);
}
