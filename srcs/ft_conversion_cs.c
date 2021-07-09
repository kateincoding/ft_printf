/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_cs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 05:23:04 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/08 22:53:16 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print_char - print a char at printf
** @lista: the main string passed to the function
** Return: An integer
*/

int	print_char(t_fields *str, va_list lista)
{
	char	c;

	c = va_arg(lista, int);
	return (ft_putchar_fd(c, str->fd));
}

/*
** print_str - print a char at printf
** @lista: the main string passed to the function
** Return: An integer
*/

int	print_str(t_fields *str, va_list lista)
{
	unsigned int	count;
	char			*av;

	count = 0;
	av = va_arg(lista, char *);
	if (!av || av == NULL)
	{
		count += ft_putchar_fd('(', str->fd);
		count += ft_putchar_fd('n', str->fd);
		count += ft_putchar_fd('u', str->fd);
		count += ft_putchar_fd('l', str->fd);
		count += ft_putchar_fd('l', str->fd);
		count += ft_putchar_fd(')', str->fd);
		return (6);
	}
	while (*av)
	{
		count += write(str->fd, &(*av++), 1);
	}
	return (count);
}
