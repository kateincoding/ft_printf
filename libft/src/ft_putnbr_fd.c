/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 08:28:55 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/21 13:24:35 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	putnbr(long n, int fd)
{
	int	counter;

	counter = 0;
	if (n == -2147483648)
		counter += ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		counter += ft_putchar_fd('-', fd);
		counter += putnbr(-n, fd);
	}
	else if (n >= 10)
	{
		counter += putnbr(n / 10, fd);
		counter += ft_putchar_fd(n % 10 + '0', fd);
	}
	else if (n < 10)
		counter += ft_putchar_fd(n + '0', fd);
	return (counter);
}

int	ft_putnbr_fd(int n, int fd)
{
	return (putnbr(n, fd));
}
