/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_cs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 05:23:04 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/08 11:56:51 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print_char - print a char at printf
** @lista: the main string passed to the function
** Return: An integer
*/

int	print_char(va_list lista)
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

int	print_str(va_list lista)
{
	unsigned int	count;
	char			*av;

	count = 0;
	av = va_arg(lista, char *);
	if (!av || av == NULL)
	{
		ft_putchar('(');
		ft_putchar('n');
		ft_putchar('u');
		ft_putchar('l');
		ft_putchar('l');
		ft_putchar(')');
		return (6);
	}
	while (*av)
	{
		write(1, &(*av++), 1);
		count++;
	}
	return (count);
}
