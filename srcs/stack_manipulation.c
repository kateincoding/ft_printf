/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 04:02:52 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/08 20:29:35 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_stack(t_fields *str, const char *input, int fd)
{
	str->format = (char *)input;
	str->idx = 0;
	str->fd = fd;
	str->lenght = 0;
	str->minus = 0;
	str->zero = 0;
	str->width = 0;
	str->final_width = 0;
	str->wildcard = 0;
	str->precision = -1;
	str->space = 0;
	str->len = 0;
	str->break_flag = 0;
}

void	finalize_stack(t_fields *str)
{
	free(str);
}
