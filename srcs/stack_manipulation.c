/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 04:02:52 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/02 18:04:09 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void initialize_stack(const char *input, int fd)
{
    str = (t_fields *)ft_memalloc(sizeof(t_fields));

	str->format = (char *)input;
	str->idx = 0;
	str->fd = fd;
	str->lenght = 0;
	str->minus = 0;
	str->zero = 0;
	str->width = 0;
	str->wildcard = 0;
	str->precision = 0; /* antes -1 */
	str->space = 0;
}

void finalize_stack(void)
{
    free(str);
}
