/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:35:30 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/20 19:40:29 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
