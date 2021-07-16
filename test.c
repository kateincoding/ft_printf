/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:29:11 by ciglesia          #+#    #+#             */
/*   Updated: 2021/07/15 22:16:36 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

#define RED "\norig->  \e[38;2;255;0;0m"
#define E0M "\e[0mkate->  "

void test_c(void)
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

//	printf("        0000000000000000000");
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

void test_s(void)
{
/*
	printf("->1orig %d\n", printf("%s", ""));
	printf("->1kate %d\n", ft_printf("%s", ""));

	printf("->orig %d\n", printf("%s", "0"));
	printf("->kate %d\n", ft_printf("%s", "0"));

	printf("orig->3 %d\n", printf("%s %s", "", ""));
	printf("kate->3 %d\n", ft_printf("%s %s", "", ""));

	printf("orig->4 %d\n", printf("%s %s", "0", "1"));
	ft_printf("kate->4 %d\n", ft_printf("%s %s", "0", "1"));

	printf("orig->5 %d\n", printf(" %s %s ", "0", "1"));
	printf("kate->5 %d\n", ft_printf(" %s %s ", "0", "1"));

	printf("orig->6 %d\n", printf(" %s %s ", "", ""));
	printf("kate->6 %d\n", ft_printf(" %s %s ", "", ""));

	printf("7 %d\n", printf(" %1s %1s ", "123", "4567"));
	printf("7 %d\n", ft_printf(" %1s %1s ", "123", "4567"));

	printf("8 %d\n", printf(" %4s %4s ", "123", "4567"));
	printf("8 %d\n", ft_printf(" %4s %4s ", "123", "4567"));

	printf("9 %d\n", printf(" %-4s %4s ", "123", "4567"));
	printf("9 %d\n", ft_printf(" %-4s %4s ", "123", "4567"));
	
	printf("10 %d\n", printf(" %4s %-4s ", "123", "4567"));
	printf("10 %d\n", ft_printf(" %4s %-4s ", "123", "4567"));

	printf("11 %d\n", printf(" %-4s %-4s ", "123", "4567"));
	printf("11 %d\n", ft_printf(" %-4s %-4s ", "123", "4567"));
	
	printf("12 %d\n", printf(" %-4s %-4s ", "123", "4567"));
	printf("12 %d\n", ft_printf(" %-4s %-4s ", "123", "4567"));

	printf("13 %d\n", printf(" %*s %*s ", 1, "123", 10, "4567"));
	printf("13 %d\n", ft_printf(" %*s %*s ", 1, "123", 10, "4567"));

	printf("14 %d\n", printf(" *%s %*s ", "123", 10, "4567"));
	printf("14 %d\n", ft_printf(" *%s %*s ", "123", 10, "4567"));

	printf("15 %d\n", printf(" %*s %s ", 10, "123", "4567"));
	printf("15 %d\n", ft_printf(" %*s %s ", 10, "123", "4567"));
*/
	printf("->orig:16 %d\n", printf(" %*.s %.1s ", 10, "123", "4567"));
	printf("->kate:16 %d\n", ft_printf(" %*.s %.1s ", 10, "123", "4567"));

	printf("17 %d\n", printf(" %*.0s %.2s ", 10, "123", "4567"));
	printf("17 %d\n", ft_printf(" %*.0s %.2s ", 10, "123", "4567"));

	printf("18 %d\n", printf(" %*.3s %.3s ", 10, "123", "4567"));
	printf("18 %d\n", ft_printf(" %*.3s %.3s ", 10, "123", "4567"));

	printf("19 %d\n", printf(" %*.4s %.4s ", 10, "123", "4567"));
	printf("19 %d\n", ft_printf(" %*.4s %.4s ", 10, "123", "4567"));

	printf("20 %d\n", printf(" %*.5s %.5s ", 10, "123", "4567"));
	printf("20 %d\n", ft_printf(" %*.5s %.5s ", 10, "123", "4567"));

	printf("21 %d\n", printf(" %*.5s %*.5s ", 10, "123", 10, "4567"));
	printf("21 %d\n", ft_printf(" %*.5s %*.5s ", 10, "123", 10, "4567"));

	printf("22 %d\n", printf(" %*.5s %*.5s ", -10, "123", 10, "4567"));
	printf("22 %d\n", ft_printf(" %*.5s %*.5s ", -10, "123", 10, "4567"));

	printf("23 %d\n", printf(" %*.5s %*.5s ", 10, "123", -10, "4567"));
	printf("23 %d\n", ft_printf(" %*.5s %*.5s ", 10, "123", -10, "4567"));

	printf("24 %d\n", printf(" %*.5s %*.5s ", -10, "123", -10, "4567"));
	printf("24 %d\n", ft_printf(" %*.5s %*.5s ", -10, "123", -10, "4567"));
	
	printf("25 %d\n", printf(" %10.s %1.s ", "123", "4567"));
	printf("25 %d\n", ft_printf(" %10.s %1.s ", "123", "4567"));

	printf("26 %d\n", printf(" %0.s %0.s ", "123", "4567"));
	printf("26 %d\n", ft_printf(" %0.s %0.s ", "123", "4567"));

	printf("27 %d\n", printf(" %.s %.s ", "123", "4567"));
	printf("27 %d\n", ft_printf(" %.s %.s ", "123", "4567"));

	printf("28 %d\n", printf(" %3.3s %3.3s ", "123", "4567"));
	printf("28 %d\n", ft_printf(" %3.3s %3.3s ", "123", "4567"));

	printf("29 %d\n", printf(" %4.3s %-4.3s ", "123", "4567"));
	printf("29 %d\n", ft_printf(" %4.3s %-4.3s ", "123", "4567"));

	printf("30 %d\n", printf("%.s", ""));
	printf("30 %d\n", ft_printf("%.s", ""));

	printf("31 %d\n", printf("%.0s", ""));
	printf("31 %d\n", ft_printf("%.0s", ""));

	printf("32 %d\n", printf("%.1s", ""));
	printf("32 %d\n", ft_printf("%.1s", ""));

	printf("33 %d\n", printf(" %4.2s %-4.2s ", "123", "4567"));
	printf("33 %d\n", ft_printf(" %4.2s %-4.2s ", "123", "4567"));

	# ifdef __APPLE__
		printf("34 %d\n", printf(" %-3.s ", NULL));
		printf("34 %d\n", ft_printf(" %-3.s ", NULL));

		printf("35 %d\n", printf(" %-9.1s ", NULL));
		printf("35 %d\n", ft_printf(" %-9.1s ", NULL));
		
		printf("36 %d\n", printf(" %.*s ", -2, NULL));
		printf("36 %d\n", ft_printf(" %.*s ", -2, NULL));
	# endif
}

int main(void)
{
//	test_c();
	test_s();
	return (0);
}
