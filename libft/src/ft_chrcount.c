/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:14:08 by ksoto             #+#    #+#             */
/*   Updated: 2021/06/27 13:33:41 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_chrcount(const char *s, char c)
{
	unsigned int	i;
	int				counter;

	i = 0;
	counter = 0;

	while (s[i])
	{
		if (s[i] == c)
			counter++, i++;
		while (s[i] != c && s[i])
			i++;
	}
	return (counter);
}
