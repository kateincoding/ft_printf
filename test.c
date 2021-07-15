/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:29:11 by ciglesia          #+#    #+#             */
/*   Updated: 2021/07/15 18:40:33 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

#define RED "\norig->  \e[38;2;255;0;0m"
#define E0M "\e[0mkate->  "

int main()
{
	printf(RED"|%c|\n", '0');
	ft_printf(E0M"|%c|\n", '0');

	printf(RED"| %c |\n", '0');
	ft_printf(E0M"| %c |\n", '0');

	printf(RED"|10%c|\n", '0');
	ft_printf(E0M"|10%c|\n", '0');

	printf(RED"|%10c|\n", '0');
	ft_printf(E0M"|%10c|\n", '0');

	printf(RED"|-10%c|\n", '0');
	ft_printf(E0M"|-10%c|\n", '0');

	printf(RED"|%-10c|\n", '0');
	ft_printf(E0M"|%-10c|\n", '0');

	printf(RED"|%-10c|\n", '0');
	ft_printf(E0M"|%-10c|\n", '0');

	printf(RED"|%*c|\n", 1, '0');
	ft_printf(E0M"|%*c|\n", 1, '0');

	printf(RED"|%*c|\n", 0, '0');
	ft_printf(E0M"|%*c|\n", 0, '0');

	printf(RED"|%*c|\n", 2, '0');
	ft_printf(E0M"|%*c|\n", 2, '0');

	printf(RED"|%*c|\n", -2, '0');
	ft_printf(E0M"|%*c|\n", -2, '0');

	printf(RED"|%*c|\n", 0, '0');
	ft_printf(E0M"|%*c|\n", 0, '0');

	printf(RED"|%*c|\n", 10, '0');
	ft_printf(E0M"|%*c|\n", 10, '0');

	printf(RED"|%*c|\n", -10, '0');
	ft_printf(E0M"|%*c|\n", -10, '0');

	printf(RED"|%*c%*c|\n", -10, '0', 10, '1');
	ft_printf(E0M"|%*c%*c|\n", -10, '0', 10, '1');

	printf(RED"|*%c%*c|\n", '0', 10, '1');
	ft_printf(E0M"|*%c%*c|\n", '0', 10, '1');

	printf(RED"|%*c%c*|\n", -10, '0', '1');
	ft_printf(E0M"|%*c%c*|\n", -10, '0', '1');

	printf(RED"|%-10c*|\n",'0');
	ft_printf(E0M"|%-10c*|\n",'0');

	printf(RED"|%-10c%*c%c*|\n",'0', 10, '1', '2');
	ft_printf(E0M"|%-10c%*c%c*|\n",'0', 10, '1', '2');

	printf(RED"|%c%c%c*|\n",'0', '1', '2');
	ft_printf(E0M"|%c%c%c*|\n",'0', '1', '2');

	printf(RED"|%-c%-c%c*|\n", 1, '0', 0);
	ft_printf(E0M"|%-c%-c%c*|\n", 1, '0', 0);

	printf(RED"|%c|\n", '0' - 256);
	ft_printf(E0M"|%c|\n", '0' - 256);

	printf(RED"|%c|\n", '0' + 256);
	ft_printf(E0M"|%c|\n", '0' + 256);

	printf(RED"|%c|\n", 0);
	ft_printf(E0M"|%c|\n", 0);

	printf(RED"|0%c|\n", 0);
	ft_printf(E0M"|0%c|\n", 0);

	printf(RED"|%c|\n", -129);
	ft_printf(E0M"|%c|\n", -129);

	printf(RED"|%c|\n", 128);
	ft_printf(E0M"|%c|\n", 128);

	printf(RED"|%-*c|\n", 10, '1');
	ft_printf(E0M"|%-*c|\n", 10, '1');

	printf(RED"| -%*c* -%-*c* |\n", -2, 0, 2, 0);
	ft_printf(E0M"| -%*c* -%-*c* |\n", -2, 0, 2, 0);

	printf(RED"| -%-*c* -%-*c* |\n", 2, 0, -2, 0);
	ft_printf(E0M"| -%-*c* -%-*c* |\n", 2, 0, -2, 0);

	printf(RED"| -%*c* -%-*c* |\n", -1, 0, 1, 0);
	ft_printf(E0M"| -%*c* -%-*c* |\n", -1, 0, 1, 0);

	printf(RED"| -%-*c* -%-*c* |\n", 2, 0, -2, 0);
	ft_printf(E0M"| -%-*c* -%-*c* |\n", 2, 0, -2, 0);

	printf(RED"| -%-2c* -%2c* |\n", 0, 0);
	ft_printf(E0M"| -%-2c* -%2c* |\n", 0, 0);

}
