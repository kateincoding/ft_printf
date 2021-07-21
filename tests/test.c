/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:29:11 by ciglesia          #+#    #+#             */
/*   Updated: 2021/07/21 13:48:53 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

#define RED "\norig->  \e[38;2;255;0;0m"
#define E0M "\e[0mkate->  "

void test_plus(void)
{
	printf(RED);
	printf("->Result7 %d\n", printf(" %+d ", 16));
	ft_printf(E0M);
	printf("->Result7 %d\n", ft_printf(" %+d ", 16));

	printf(RED);
	printf("->Result8 %d\n", printf(" %+d ", 17));
	ft_printf(E0M);
	printf("->Result8 %d\n", ft_printf(" %+d ", 17));

	printf(RED);
	printf("->Result9 %d\n", printf(" %+d ", 99));
	ft_printf(E0M);
	printf("->Result9 %d\n", ft_printf(" %+d ", 99));
}


void test_c(void)
{
	printf(RED);
	printf("%d\n", printf("|%c|", '0'));
	ft_printf(E0M);
	printf("%d\n", ft_printf("|%c|", '0'));

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

void test_s(void)
{
	printf(RED);
	printf("->1orig %d\n", printf("%s", ""));
	ft_printf(E0M);
	printf("->1kate %d\n", ft_printf("%s", ""));

	printf(RED);
	printf("->orig %d\n", printf("%s", "0"));
	ft_printf(E0M);
	printf("->kate %d\n", ft_printf("%s", "0"));

	printf(RED);
	printf("orig->3 %d\n", printf("%s %s", "", ""));
	ft_printf(E0M);
	printf("kate->3 %d\n", ft_printf("%s %s", "", ""));

	printf(RED);
	printf("orig->4 %d\n", printf("%s %s", "0", "1"));
	ft_printf(E0M);
	ft_printf("kate->4 %d\n", ft_printf("%s %s", "0", "1"));

	printf(RED);
	printf("orig->5 %d\n", printf(" %s %s ", "0", "1"));
	ft_printf(E0M);
	printf("kate->5 %d\n", ft_printf(" %s %s ", "0", "1"));

	printf(RED);
	printf("orig->6 %d\n", printf(" %s %s ", "", ""));
	ft_printf(E0M);
	printf("kate->6 %d\n", ft_printf(" %s %s ", "", ""));

	printf(RED);
	printf("7 %d\n", printf(" %1s %1s ", "123", "4567"));
	ft_printf(E0M);
	printf("7 %d\n", ft_printf(" %1s %1s ", "123", "4567"));

	printf(RED);
	printf("8 %d\n", printf(" %4s %4s ", "123", "4567"));
	ft_printf(E0M);
	printf("8 %d\n", ft_printf(" %4s %4s ", "123", "4567"));

	printf(RED);
	printf("9 %d\n", printf(" |%-4s| |%4s| ", "123", "4567"));
	ft_printf(E0M);
	printf("9 %d\n", ft_printf(" |%-4s| |%4s| ", "123", "4567"));
	
	printf(RED);
	printf("10 %d\n", printf(" |%4s| |%-4s| ", "123", "4567"));
	ft_printf(E0M);
	printf("10 %d\n", ft_printf(" |%4s| |%-4s| ", "123", "4567"));

	printf(RED);
	printf("11 %d\n", printf(" |%-4s| |%-4s| ", "123", "4567"));
	ft_printf(E0M);
	printf("11 %d\n", ft_printf(" |%-4s| |%-4s| ", "123", "4567"));
	
	printf(RED);
	printf("12 %d\n", printf(" |%-4s| |%-4s| ", "123", "4567"));
	ft_printf(E0M);
	printf("12 %d\n", ft_printf(" |%-4s| |%-4s| ", "123", "4567"));

	printf(RED);
	printf("13 %d\n", printf(" |%*s| |%*s| ", 1, "123", 10, "4567"));
	ft_printf(E0M);
	printf("13 %d\n", ft_printf(" |%*s| |%*s| ", 1, "123", 10, "4567"));

	printf(RED);
	printf("14 %d\n", printf(" |*%s| |%*s| ", "123", 10, "4567"));
	ft_printf(E0M);
	printf("14 %d\n", ft_printf(" |*%s| |%*s| ", "123", 10, "4567"));

	printf(RED);
	printf("15 %d\n", printf(" %*s %s ", 10, "123", "4567"));
	ft_printf(E0M);
	printf("15 %d\n", ft_printf(" %*s %s ", 10, "123", "4567"));

	printf(RED);
	printf("->16 orig: %d\n", printf(" %*.s %.1s ", 10, "123", "4567"));
	ft_printf(E0M);
	printf("->16 kate: %d\n", ft_printf(" %*.s %.1s ", 10, "123", "4567"));

	printf(RED);
	printf("->17 orig: %d\n", printf(" %*.0s %.2s ", 10, "123", "4567"));
	ft_printf(E0M);
	printf("->17 kate: %d\n", ft_printf(" %*.0s %.2s ", 10, "123", "4567"));

	printf(RED);
	printf("->18 orig: %d\n", printf(" %*.3s %.3s ", 10, "123", "4567"));
	ft_printf(E0M);
	printf("->18 kate: %d\n", ft_printf(" %*.3s %.3s ", 10, "123", "4567"));

	printf(RED);
	printf("->19 orig: %d\n", printf(" %*.4s %.4s ", 10, "123", "4567"));
	ft_printf(E0M);
	printf("->19 kate: %d\n", ft_printf(" %*.4s %.4s ", 10, "123", "4567"));

	printf(RED);
	printf("->20 orig: %d\n", printf(" %*.5s %.5s ", 10, "123", "4567"));
	ft_printf(E0M);
	printf("->20 kate: %d\n", ft_printf(" %*.5s %.5s ", 10, "123", "4567"));

	printf(RED);
	printf("->21 orig: %d\n", printf(" %*.5s %*.5s ", 10, "123", 10, "4567"));
	ft_printf(E0M);
	printf("->21 orig: %d\n", ft_printf(" %*.5s %*.5s ", 10, "123", 10, "4567"));

	printf(RED);
	printf("->22 orig: %d\n", printf(" %*.5s %*.5s ", -10, "123", 10, "4567"));
	ft_printf(E0M);
	printf("->22 orig: %d\n", ft_printf(" %*.5s %*.5s ", -10, "123", 10, "4567"));

	printf(RED);
	printf("->23 orig: %d\n", printf(" %*.5s %*.5s ", 10, "123", -10, "4567"));
	ft_printf(E0M);
	printf("->23 orig: %d\n", ft_printf(" %*.5s %*.5s ", 10, "123", -10, "4567"));

	printf(RED);
	printf("->24 orig: %d\n", printf(" %*.5s %*.5s ", -10, "123", -10, "4567"));
	ft_printf(E0M);
	printf("->24 orig: %d\n", ft_printf(" %*.5s %*.5s ", -10, "123", -10, "4567"));
	
	printf(RED);
	printf("25 %d\n", printf(" %10.s %1.s ", "123", "4567"));
	ft_printf(E0M);
	printf("25 %d\n", ft_printf(" %10.s %1.s ", "123", "4567"));

	printf(RED);
	printf("26 %d\n", printf(" %0.s %0.s ", "123", "4567"));
	ft_printf(E0M);
	printf("26 %d\n", ft_printf(" %0.s %0.s ", "123", "4567"));

	printf(RED);
	printf("27 %d\n", printf(" %.s %.s ", "123", "4567"));
	ft_printf(E0M);
	printf("27 %d\n", ft_printf(" %.s %.s ", "123", "4567"));

	printf(RED);
	printf("28 %d\n", printf(" %3.3s %3.3s ", "123", "4567"));
	ft_printf(E0M);
	printf("28 %d\n", ft_printf(" %3.3s %3.3s ", "123", "4567"));

	printf(RED);
	printf("29 %d\n", printf(" %4.3s %-4.3s ", "123", "4567"));
	ft_printf(E0M);
	printf("29 %d\n", ft_printf(" %4.3s %-4.3s ", "123", "4567"));

	printf(RED);
	printf("30 %d\n", printf("%.s", ""));
	ft_printf(E0M);
	printf("30 %d\n", ft_printf("%.s", ""));

	printf(RED);
	printf("31 %d\n", printf("%.0s", ""));
	ft_printf(E0M);
	printf("31 %d\n", ft_printf("%.0s", ""));

	printf(RED);
	printf("32 %d\n", printf("%.1s", ""));
	ft_printf(E0M);
	printf("32 %d\n", ft_printf("%.1s", ""));

	printf(RED);
	printf("33 %d\n", printf(" %4.2s %-4.2s ", "123", "4567"));
	ft_printf(E0M);
	printf("33 %d\n", ft_printf(" %4.2s %-4.2s ", "123", "4567"));

	# ifdef __APPLE__

		printf(RED);
		printf("34 %d\n", printf("| %s |", NULL));
		ft_printf(E0M);
		printf("34 %d\n", ft_printf("| %s |", NULL));

		printf(RED);
		printf("34 %d\n", printf("| %-10.s |", NULL));
		ft_printf(E0M);
		printf("34 %d\n", ft_printf("| %-10.s |", NULL));

		printf(RED);
		printf("34 %d\n", printf("| %-3.s |", NULL));
		ft_printf(E0M);
		printf("34 %d\n", ft_printf("| %-3.s |", NULL));

		printf(RED);
		printf("35 %d\n", printf(" %-9.1s ", NULL));
		ft_printf(E0M);
		printf("35 %d\n", ft_printf(" %-9.1s ", NULL));

		printf(RED);
		printf("35 %d\n", printf(" %-9.3s ", NULL));
		ft_printf(E0M);
		printf("35 %d\n", ft_printf(" %-9.3s ", NULL));

		printf(RED);
		printf("35 %d\n", printf(" %9.3s ", NULL));
		ft_printf(E0M);
		printf("35 %d\n", ft_printf(" %9.3s ", NULL));

		printf(RED);
		printf("35 %d\n", printf(" %3.9s ", NULL));
		ft_printf(E0M);
		printf("35 %d\n", ft_printf(" %3.9s ", NULL));

		printf(RED);
		printf("36 %d\n", printf(" %.*s ", 2, NULL));
		ft_printf(E0M);
		printf("36 %d\n", ft_printf(" %.*s ", 2, NULL));

		printf("36 %d\n", printf(" %.*s ", 10, NULL));
		printf("36 %d\n", ft_printf(" %.*s ", 10, NULL));

		printf("36 %d\n", printf(" %.*s ", -2, NULL));
		printf("36 %d\n", ft_printf(" %.*s ", -2, NULL));

		printf("36 %d\n", printf(" %.*s ", -10, NULL));
		printf("36 %d\n", ft_printf(" %.*s ", -10, NULL));
	# endif
}

void test2_s(void)
{
	printf("->1-orig %d\n", printf("%s", ""));
	printf("->1-kate %d\n", ft_printf("%s", ""));

	printf("->2orig %d\n", printf(" %s", ""));
	printf("->2kate %d\n", ft_printf(" %s", ""));

	printf("->3orig %d\n", printf("%s ", ""));
	printf("->3kate %d\n", ft_printf("%s ", ""));

	printf("->4orig %d\n", printf(" %s ", ""));
	printf("->4kate %d\n", ft_printf(" %s ", ""));

	printf("->5orig %d\n", printf(" %s ", "-"));
	printf("->5kate %d\n", ft_printf(" %s ", "-"));

	printf("->6orig %d\n", printf(" %s %s ", "", "-"));
	printf("->6kate %d\n", ft_printf(" %s %s ", "", "-"));

	printf("->7orig %d\n", printf(" %s %s ", " - ", ""));
	printf("->7kate %d\n", ft_printf(" %s %s ", " - ", ""));

	printf("->8orig %d\n", printf(" %s %s %s %s ", " - ", "", "4", ""));
	printf("->8kate %d\n", ft_printf(" %s %s %s %s ", " - ", "", "4", ""));

	printf("->9orig %d\n", printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 "));
	printf("->9kate %d\n", ft_printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 "));
}

void test3_d(void)
{

	printf(RED);
	printf("->Result1 %d\n", printf(" %d ", 0));
	ft_printf(E0M);
	printf("->Result1 %d\n", ft_printf(" %d ", 0));

	printf(RED);
	printf("->Result2 %d\n", printf(" %d ", -1));
	ft_printf(E0M);
	printf("->Result2 %d\n", ft_printf(" %d ", -1));

	printf(RED);
	printf("->Result3 %d\n", printf(" %d ", 1));
	ft_printf(E0M);
	printf("->Result3 %d\n", ft_printf(" %d ", 1));

	printf(RED);
	printf("->Result4 %d\n", printf(" %d ", 9));
	ft_printf(E0M);
	printf("->Result4 %d\n", ft_printf(" %d ", 9));

	printf(RED);
	printf("->Result5 %d\n", printf(" %d ", 10));
	ft_printf(E0M);
	printf("->Result5 %d\n", ft_printf(" %d ", 10));

	printf(RED);
	printf("->Result6 %d\n", printf(" %d ", 11));
	ft_printf(E0M);
	printf("->Result6 %d\n", ft_printf(" %d ", 11));

	printf(RED);
	printf("->Result7 %d\n", printf(" %d ", 15));
	ft_printf(E0M);
	printf("->Result7 %d\n", ft_printf(" %d ", 15));

	printf(RED);
	printf("->Result8 %d\n", printf(" %d ", 16));
	ft_printf(E0M);
	printf("->Result8 %d\n", ft_printf(" %d ", 16));

	printf(RED);
	printf("->Result9 %d\n", printf(" %d ", 17));
	ft_printf(E0M);
	printf("->Result9 %d\n", ft_printf(" %d ", 17));

	printf(RED);
	printf("->Result10 %d\n", printf(" %d ", 99));
	ft_printf(E0M);
	printf("->Result10 %d\n", ft_printf(" %d ", 99));

	printf(RED);
	printf("->Result11 %d\n", printf(" %d ", 100));
	ft_printf(E0M);
	printf("->Result11 %d\n", ft_printf(" %d ", 100));

	printf(RED);
	printf("->Result12 %d\n", printf(" %d ", 101));
	ft_printf(E0M);
	printf("->Result12 %d\n", ft_printf(" %d ", 101));

	printf(RED);
	printf("->Result13 %d\n", printf(" %d ", -9));
	ft_printf(E0M);
	printf("->Result13 %d\n", ft_printf(" %d ", -9));

	printf(RED);
	printf("->Result14d %d\n", printf(" %d ", -10));
	ft_printf(E0M);
	printf("->Result14d %d\n", ft_printf(" %d ", -10));

	printf(RED);
	printf("->Result14i %d\n", printf(" %i ", -10));
	ft_printf(E0M);
	printf("->Result14i %d\n", ft_printf(" %i ", -10));

	printf(RED);
	printf("->Result14u %d\n", printf(" %u ", -10));
	ft_printf(E0M);
	printf("->Result14u %d\n", ft_printf(" %u ", -10));

	printf(RED);
	printf("->Result15 %d\n", printf(" %d ", -11));
	ft_printf(E0M);
	printf("->Result15 %d\n", ft_printf(" %d ", -11));

	printf(RED);
	printf("->Result16 %d\n", printf(" %d ", -14));
	ft_printf(E0M);
	printf("->Result16 %d\n", ft_printf(" %d ", -14));

	printf(RED);
	printf("->Result17 %d\n", printf(" %d ", -15));
	ft_printf(E0M);
	printf("->Result17 %d\n", ft_printf(" %d ", -15));

	printf(RED);
	printf("->Result18 %d\n", printf(" %d ", -16));
	ft_printf(E0M);
	printf("->Result18 %d\n", ft_printf(" %d ", -16));

	printf(RED);
	printf("->Result19 %d\n", printf(" %d ", -99));
	ft_printf(E0M);
	printf("->Result19 %d\n", ft_printf(" %d ", -99));

	printf(RED);
	printf("->Result20 %d\n", printf(" %d ", -100));
	ft_printf(E0M);
	printf("->Result20 %d\n", ft_printf(" %d ", -100));

	printf(RED);
	printf("->Result21 %d\n", printf(" %d ", -101));
	ft_printf(E0M);
	printf("->Result21 %d\n", ft_printf(" %d ", -101));

	printf(RED);
	printf("->Result22 %d\n", printf(" %d ", INT_MAX));
	ft_printf(E0M);
	printf("->Result22 %d\n", ft_printf(" %d ", INT_MAX));

	printf(RED);
	printf("->Result23 %d\n", printf(" %d ", INT_MIN));
	ft_printf(E0M);
	printf("->Result23 %d\n", ft_printf(" %d ", INT_MIN));

	printf(RED);
	printf("->Result24 %d\n", printf(" %d ", LONG_MAX));
	ft_printf(E0M);
	printf("->Result24 %d\n", ft_printf(" %d ", LONG_MAX));

	printf(RED);
	printf("->Result25 %d\n", printf(" %d ", LONG_MIN));
	ft_printf(E0M);
	printf("->Result25 %d\n", ft_printf(" %d ", LONG_MIN));

	printf(RED);
	printf("->Result26 %d\n", printf(" %d ", UINT_MAX));
	ft_printf(E0M);
	printf("->Result26 %d\n", ft_printf(" %d ", UINT_MAX));

	printf(RED);
	printf("->Result27 %d\n", printf(" %d ", ULONG_MAX));
	ft_printf(E0M);
	printf("->Result27 %d\n", ft_printf(" %d ", ULONG_MAX));

	printf(RED);
	printf("->Result28 %d\n", printf(" %d ", ULONG_LONG_MAX));
	ft_printf(E0M);
	printf("->Result28 %d\n", ft_printf(" %d ", ULONG_LONG_MAX));

	printf(RED);
	printf("->Result29 %d\n", printf(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	ft_printf(E0M);
	printf("->Result29 %d\n", ft_printf(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
}

void test4_i(void)
{
	printf(RED);
	printf("->Result1 %d\n", printf(" %i ", 0));
	ft_printf(E0M);
	printf("->Result1 %d\n", ft_printf(" %i ", 0));

	printf(RED);
	printf("->Result2 %d\n", printf(" %i ", -1));
	ft_printf(E0M);
	printf("->Result2 %d\n", ft_printf(" %i ", -1));

	printf(RED);
	printf("->Result3 %d\n", printf(" %i ", 1));
	ft_printf(E0M);
	printf("->Result3 %d\n", ft_printf(" %i ", 1));

	printf(RED);
	printf("->Result4 %d\n", printf(" %i ", 9));
	ft_printf(E0M);
	printf("->Result4 %d\n", ft_printf(" %i ", 9));

	printf(RED);
	printf("->Result5 %d\n", printf(" %i ", 10));
	ft_printf(E0M);
	printf("->Result5 %d\n", ft_printf(" %i ", 10));

	printf(RED);
	printf("->Result6 %d\n", printf(" %i ", 11));
	ft_printf(E0M);
	printf("->Result6 %d\n", ft_printf(" %i ", 11));

	printf(RED);
	printf("->Result7 %d\n", printf(" %i ", 15));
	ft_printf(E0M);
	printf("->Result7 %d\n", ft_printf(" %i ", 15));

	printf(RED);
	printf("->Result8 %d\n", printf(" %i ", 16));
	ft_printf(E0M);
	printf("->Result8 %d\n", ft_printf(" %i ", 16));

	printf(RED);
	printf("->Result9 %d\n", printf(" %i ", 17));
	ft_printf(E0M);
	printf("->Result9 %d\n", ft_printf(" %i ", 17));

	printf(RED);
	printf("->Result10 %d\n", printf(" %i ", 99));
	ft_printf(E0M);
	printf("->Result10 %d\n", ft_printf(" %i ", 99));

	printf(RED);
	printf("->Result11 %d\n", printf(" %i ", 100));
	ft_printf(E0M);
	printf("->Result11 %d\n", ft_printf(" %i ", 100));

	printf(RED);
	printf("->Result12 %d\n", printf(" %i ", 101));
	ft_printf(E0M);
	printf("->Result12 %d\n", ft_printf(" %i ", 101));

	printf(RED);
	printf("->Result13 %d\n", printf(" %i ", -9));
	ft_printf(E0M);
	printf("->Result13 %d\n", ft_printf(" %i ", -9));

	printf(RED);
	printf("->Result14 %d\n", printf(" %i ", -10));
	ft_printf(E0M);
	printf("->Result14 %d\n", ft_printf(" %i ", -10));

	printf(RED);
	printf("->Result15 %d\n", printf(" %i ", -11));
	ft_printf(E0M);
	printf("->Result15 %d\n", ft_printf(" %i ", -11));

	printf(RED);
	printf("->Result16 %d\n", printf(" %i ", -14));
	ft_printf(E0M);
	printf("->Result16 %d\n", ft_printf(" %i ", -14));

	printf(RED);
	printf("->Result17 %d\n", printf(" %i ", -15));
	ft_printf(E0M);
	printf("->Result17 %d\n", ft_printf(" %i ", -15));

	printf(RED);
	printf("->Result18 %d\n", printf(" %i ", -16));
	ft_printf(E0M);
	printf("->Result18 %d\n", ft_printf(" %i ", -16));

	printf(RED);
	printf("->Result19 %d\n", printf(" %i ", -99));
	ft_printf(E0M);
	printf("->Result19 %d\n", ft_printf(" %i ", -99));

	printf(RED);
	printf("->Result20 %d\n", printf(" %i ", -100));
	ft_printf(E0M);
	printf("->Result20 %d\n", ft_printf(" %i ", -100));

	printf(RED);
	printf("->Result21 %d\n", printf(" %i ", -101));
	ft_printf(E0M);
	printf("->Result21 %d\n", ft_printf(" %i ", -101));

	printf(RED);
	printf("->Result22 %d\n", printf(" %i ", INT_MAX));
	ft_printf(E0M);
	printf("->Result22 %d\n", ft_printf(" %i ", INT_MAX));

	printf(RED);
	printf("->Result23 %d\n", printf(" %i ", INT_MIN));
	ft_printf(E0M);
	printf("->Result23 %d\n", ft_printf(" %i ", INT_MIN));

	printf(RED);
	printf("->Result24 %d\n", printf(" %i ", LONG_MAX));
	ft_printf(E0M);
	printf("->Result24 %d\n", ft_printf(" %i ", LONG_MAX));

	printf(RED);
	printf("->Result25 %d\n", printf(" %i ", LONG_MIN));
	ft_printf(E0M);
	printf("->Result25 %d\n", ft_printf(" %i ", LONG_MIN));

	printf(RED);
	printf("->Result26 %d\n", printf(" %i ", UINT_MAX));
	ft_printf(E0M);
	printf("->Result26 %d\n", ft_printf(" %i ", UINT_MAX));

	printf(RED);
	printf("->Result27 %d\n", printf(" %i ", ULONG_MAX));
	ft_printf(E0M);
	printf("->Result27 %d\n", ft_printf(" %i ", ULONG_MAX));

	printf(RED);
	printf("->Result28 %d\n", printf(" %i ", ULONG_LONG_MAX));
	ft_printf(E0M);
	printf("->Result28 %d\n", ft_printf(" %i ", ULONG_LONG_MAX));

	printf(RED);
	printf("->Result29 %d\n", printf(" %i %i %i %i %i %i %i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	ft_printf(E0M);
	printf("->Result29 %d\n", ft_printf(" %i %i %i %i %i %i %i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
}

void test_zero(void)
{

	printf(RED);
	printf("->Result1 %d\n", printf(" %01d ", 0));
	ft_printf(E0M);
	printf("->Result1 %d\n", ft_printf(" %01d ", 0));

	printf(RED);
	printf("->Result2 %d\n", printf(" %02d ", -1));
	ft_printf(E0M);
	printf("->Result2 %d\n", ft_printf(" %02d ", -1));

	printf(RED);
	printf("->Result3 %d\n", printf(" %04d ", 9));
	ft_printf(E0M);
	printf("->Result3 %d\n", ft_printf(" %04d ", 9));

	printf(RED);
	printf("->Result4 %d\n", printf(" %01d ", 10));
	ft_printf(E0M);
	printf("->Result4 %d\n", ft_printf(" %01d ", 10));

	printf(RED);
	printf("->Result5 %d\n", printf(" %02d ", 11));
	ft_printf(E0M);
	printf("->Result5 %d\n", ft_printf(" %02d ", 11));

	printf(RED);
	printf("->Result6 %d\n", printf(" %03d ", 15));
	ft_printf(E0M);
	printf("->Result6 %d\n", ft_printf(" %03d ", 15));

	printf(RED);
	printf("->Result7 %d\n", printf(" %04d ", 16));
	ft_printf(E0M);
	printf("->Result7 %d\n", ft_printf(" %04d ", 16));

	printf(RED);
	printf("->Result8 %d\n", printf(" %05d ", 17));
	ft_printf(E0M);
	printf("->Result8 %d\n", ft_printf(" %05d ", 17));

	printf(RED);
	printf("->Result9 %d\n", printf(" %01d ", 99));
	ft_printf(E0M);
	printf("->Result9 %d\n", ft_printf(" %01d ", 99));

	printf(RED);
	printf("->Result10 %d\n", printf(" %02d ", 100));
	ft_printf(E0M);
	printf("->Result10 %d\n", ft_printf(" %02d ", 100));

	printf(RED);
	printf("->Result11 %d\n", printf(" %03d ", 101));
	ft_printf(E0M);
	printf("->Result11 %d\n", ft_printf(" %03d ", 101));

	printf(RED);
	printf("->Result12 %d\n", printf(" %01d ", -9));
	ft_printf(E0M);
	printf("->Result12 %d\n", ft_printf(" %01d ", -9));

	printf(RED);
	printf("->Result13 %d\n", printf(" %02d ", -10));
	ft_printf(E0M);
	printf("->Result13 %d\n", ft_printf(" %02d ", -10));

	printf(RED);
	printf("->Result14 %d\n", printf(" %03d ", -11));
	ft_printf(E0M);
	printf("->Result14 %d\n", ft_printf(" %03d ", -11));

	printf(RED);
	printf("->Result15 %d\n", printf(" %04d ", -14));
	ft_printf(E0M);
	printf("->Result15 %d\n", ft_printf(" %04d ", -14));

	printf(RED);
	printf("->Result16 %d\n", printf(" %05d ", -15));
	ft_printf(E0M);
	printf("->Result16 %d\n", ft_printf(" %05d ", -15));

	printf(RED);
	printf("->Result17 %d\n", printf(" %06d ", -16));
	ft_printf(E0M);
	printf("->Result17 %d\n", ft_printf(" %06d ", -16));

	printf(RED);
	printf("->Result18 %d\n", printf(" %01d ", -99));
	ft_printf(E0M);
	printf("->Result18 %d\n", ft_printf(" %01d ", -99));

	printf(RED);
	printf("->Result19 %d\n", printf(" %02d ", -100));
	ft_printf(E0M);
	printf("->Result19 %d\n", ft_printf(" %02d ", -100));

	printf(RED);
	printf("->Result20 %d\n", printf(" %03d ", -101));
	ft_printf(E0M);
	printf("->Result20 %d\n", ft_printf(" %03d ", -101));

	printf(RED);
	printf("->Result21 %d\n", printf(" %09d ", INT_MAX));
	ft_printf(E0M);
	printf("->Result21 %d\n", ft_printf(" %09d ", INT_MAX));

	printf(RED);
	printf("->Result22 %d\n", printf(" %010d ", INT_MIN));
	ft_printf(E0M);
	printf("->Result22 %d\n", ft_printf(" %010d ", INT_MIN));

	printf(RED);
	printf("->Result23 %d\n", printf(" %011d ", LONG_MAX));
	ft_printf(E0M);
	printf("->Result23 %d\n", ft_printf(" %011d ", LONG_MAX));

	printf(RED);
	printf("->Result24 %d\n", printf(" %012d ", LONG_MIN));
	ft_printf(E0M);
	printf("->Result24 %d\n", ft_printf(" %012d ", LONG_MIN));

	printf(RED);
	printf("->Result25 %d\n", printf(" %013d ", UINT_MAX));
	ft_printf(E0M);
	printf("->Result25 %d\n", ft_printf(" %013d ", UINT_MAX));

	printf(RED);
	printf("->Result26 %d\n", printf(" %014d ", ULONG_MAX));
	ft_printf(E0M);
	printf("->Result26 %d\n", ft_printf(" %014d ", ULONG_MAX));

	printf(RED);
	printf("->Result27 %d\n", printf(" %015d ", ULONG_LONG_MAX));
	ft_printf(E0M);
	printf("->Result27 %d\n", ft_printf(" %015d ", ULONG_LONG_MAX));

	printf(RED);
	printf("->Result28 %d\n", printf(" %09d %010d %011d %012d %013d %014d %015d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	ft_printf(E0M);
	printf("->Result28 %d\n", ft_printf(" %09d %010d %011d %012d %013d %014d %015d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
//	SUBCATEGORY(29, 56, cout << endl << FG_LGRAY << "subcategory: i" << RESET_ALL << endl;)

	printf(RED);
	printf("->Result29 %d\n", printf(" %01i ", 0));
	ft_printf(E0M);
	printf("->Result29 %d\n", ft_printf(" %01i ", 0));

	printf(RED);
	printf("->Result30 %d\n", printf(" %02i ", -1));
	ft_printf(E0M);
	printf("->Result30 %d\n", ft_printf(" %02i ", -1));

	printf(RED);
	printf("->Result31 %d\n", printf(" %03i ", 1));
	ft_printf(E0M);
	printf("->Result31 %d\n", ft_printf(" %03i ", 1));

	printf(RED);
	printf("->Result32 %d\n", printf(" %04i ", 9));
	ft_printf(E0M);
	printf("->Result32 %d\n", ft_printf(" %04i ", 9));

	printf(RED);
	printf("->Result33 %d\n", printf(" %01i ", 10));
	ft_printf(E0M);
	printf("->Result33 %d\n", ft_printf(" %01i ", 10));

	printf(RED);
	printf("->Result34 %d\n", printf(" %02i ", 11));
	ft_printf(E0M);
	printf("->Result34 %d\n", ft_printf(" %02i ", 11));

	printf(RED);
	printf("->Result35 %d\n", printf(" %03i ", 15));
	ft_printf(E0M);
	printf("->Result35 %d\n", ft_printf(" %03i ", 15));

	printf(RED);
	printf("->Result36 %d\n", printf(" %04i ", 16));
	ft_printf(E0M);
	printf("->Result36 %d\n", ft_printf(" %04i ", 16));

	printf(RED);
	printf("->Result37 %d\n", printf(" %05i ", 17));
	ft_printf(E0M);
	printf("->Result37 %d\n", ft_printf(" %05i ", 17));

	printf(RED);
	printf("->Result38 %d\n", printf(" %01i ", 99));
	ft_printf(E0M);
	printf("->Result38 %d\n", ft_printf(" %01i ", 99));

	printf(RED);
	printf("->Result39 %d\n", printf(" %02i ", 100));
	ft_printf(E0M);
	printf("->Result39 %d\n", ft_printf(" %02i ", 100));

	printf(RED);
	printf("->Result40 %d\n", printf(" %03i ", 101));
	ft_printf(E0M);
	printf("->Result40 %d\n", ft_printf(" %03i ", 101));

	printf(RED);
	printf("->Result41 %d\n", printf(" %01i ", -9));
	ft_printf(E0M);
	printf("->Result41 %d\n", ft_printf(" %01i ", -9));

	printf(RED);
	printf("->Result42 %d\n", printf(" %02i ", -10));
	ft_printf(E0M);
	printf("->Result42 %d\n", ft_printf(" %02i ", -10));

	printf(RED);
	printf("->Result43 %d\n", printf(" %03i ", -11));
	ft_printf(E0M);
	printf("->Result43 %d\n", ft_printf(" %03i ", -11));

	printf(RED);	
	printf("->Result44 %d\n", printf(" %04i ", -14));
	ft_printf(E0M);
	printf("->Result44 %d\n", ft_printf(" %04i ", -14));

	printf(RED);
	printf("->Result45 %d\n", printf(" %05i ", -15));
	ft_printf(E0M);
	printf("->Result45 %d\n", ft_printf(" %05i ", -15));

	printf(RED);
	printf("->Result46 %d\n", printf(" %06i ", -16));
	ft_printf(E0M);
	printf("->Result46 %d\n", ft_printf(" %06i ", -16));

	printf(RED);
	printf("->Result47 %d\n", printf(" %01i ", -99));
	ft_printf(E0M);
	printf("->Result47 %d\n", ft_printf(" %01i ", -99));

	printf(RED);
	printf("->Result48 %d\n", printf(" %02i ", -100));
	ft_printf(E0M);
	printf("->Result48 %d\n", ft_printf(" %02i ", -100));

	printf(RED);
	printf("->Result49 %d\n", printf(" %03i ", -101));
	ft_printf(E0M);
	printf("->Result49 %d\n", ft_printf(" %03i ", -101));

	printf(RED);
	printf("->Result50 %d\n", printf(" %09i ", INT_MAX));
	ft_printf(E0M);
	printf("->Result50 %d\n", ft_printf(" %09i ", INT_MAX));

	printf(RED);
	printf("->Result51 %d\n", printf(" %010i ", INT_MIN));
	ft_printf(E0M);
	printf("->Result51 %d\n", ft_printf(" %010i ", INT_MIN));

	printf(RED);
	printf("->Result52 %d\n", printf(" %011i ", LONG_MAX));
	ft_printf(E0M);
	printf("->Result52 %d\n", ft_printf(" %011i ", LONG_MAX));

	printf(RED);
	printf("->Result53 %d\n", printf(" %012i ", LONG_MIN));
	ft_printf(E0M);
	printf("->Result53 %d\n", ft_printf(" %012i ", LONG_MIN));

	printf(RED);
	printf("->Result54 %d\n", printf(" %013i ", UINT_MAX));
	ft_printf(E0M);
	printf("->Result54 %d\n", ft_printf(" %013i ", UINT_MAX));

	printf(RED);
	printf("->Result55 %d\n", printf(" %014i ", ULONG_MAX));
	ft_printf(E0M);
	printf("->Result55 %d\n", ft_printf(" %014i ", ULONG_MAX));

	printf(RED);
	printf("->Result56 %d\n", printf(" %015i ", ULONG_LONG_MAX));
	ft_printf(E0M);
	printf("->Result56 %d\n", ft_printf(" %015i ", ULONG_LONG_MAX));

	printf(RED);
	printf("->Result57 %d\n", printf(" %09i %010i %011i %012i %013i %014i %015i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	ft_printf(E0M);
	printf("->Result57 %d\n", ft_printf(" %09i %010i %011i %012i %013i %014i %015i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));

//	SUBCATEGORY(57, 85, cout << endl << FG_LGRAY << "subcategory: u" << RESET_ALL << endl;)
	printf(RED);
	printf("->Result58 %d\n", printf(" %01u ", 0));
	ft_printf(E0M);
	printf("->Result58 %d\n", ft_printf(" %01u ", 0));

	printf(RED);
	printf("->Result59 %d\n", printf(" %02u ", -1));
	ft_printf(E0M);
	printf("->Result59 %d\n", ft_printf(" %02u ", -1));

	printf(RED);
	printf("->Result60 %d\n", printf(" %03u ", 1));
	ft_printf(E0M);
	printf("->Result60 %d\n", ft_printf(" %03u ", 1));

	printf(RED);
	printf("->Result61 %d\n", printf(" %04u ", 9));
	ft_printf(E0M);
	printf("->Result61 %d\n", ft_printf(" %04u ", 9));

	printf(RED);
	printf("->Result62 %d\n", printf(" %01u ", 10));
	ft_printf(E0M);
	printf("->Result62 %d\n", ft_printf(" %01u ", 10));

	printf(RED);
	printf("->Result63 %d\n", printf(" %02u ", 11));
	ft_printf(E0M);
	printf("->Result63 %d\n", ft_printf(" %02u ", 11));

	printf(RED);
	printf("->Result64 %d\n", printf(" %03u ", 15));
	ft_printf(E0M);
	printf("->Result64 %d\n", ft_printf(" %03u ", 15));

	printf(RED);
	printf("->Result65 %d\n", printf(" %04u ", 16));
	ft_printf(E0M);
	printf("->Result65 %d\n", ft_printf(" %04u ", 16));

	printf(RED);
	printf("->Result66 %d\n", printf(" %05u ", 17));
	ft_printf(E0M);
	printf("->Result66 %d\n", ft_printf(" %05u ", 17));

	printf(RED);
	printf("->Result67 %d\n", printf(" %01u ", 99));
	ft_printf(E0M);
	printf("->Result67 %d\n", ft_printf(" %01u ", 99));

	printf(RED);
	printf("->Result68 %d\n", printf(" %02u ", 100));
	ft_printf(E0M);
	printf("->Result68 %d\n", ft_printf(" %02u ", 100));

	printf(RED);
	printf("->Result69 %d\n", printf(" %03u ", 101));
	ft_printf(E0M);
	printf("->Result69 %d\n", ft_printf(" %03u ", 101));

	printf(RED);
	printf("->Result72 %d\n", printf(" %03u ", -11));
	ft_printf(E0M);
	printf("->Result72 %d\n", ft_printf(" %03u ", -11));

	printf(RED);
	printf("->Result73 %d\n", printf(" %04u ", -14));
	ft_printf(E0M);
	printf("->Result73 %d\n", ft_printf(" %04u ", -14));

	printf(RED);
	printf("->Result74 %d\n", printf(" %05u ", -15));
	ft_printf(E0M);
	printf("->Result74 %d\n", ft_printf(" %05u ", -15));

	printf(RED);
	printf("->Result75 %d\n", printf(" %06u ", -16));
	ft_printf(E0M);
	printf("->Result75 %d\n", ft_printf(" %06u ", -16));

	printf(RED);
	printf("->Result76 %d\n", printf(" %01u ", -99));
	ft_printf(E0M);
	printf("->Result76 %d\n", ft_printf(" %01u ", -99));

	printf(RED);
	printf("->Result76 %d\n", printf(" %02u ", -100));
	ft_printf(E0M);
	printf("->Result76 %d\n", ft_printf(" %02u ", -100));

	printf(RED);
	printf("->Result77 %d\n", printf(" %03u ", -101));
	ft_printf(E0M);
	printf("->Result77 %d\n", ft_printf(" %03u ", -101));

	printf(RED);
	printf("->Result78 %d\n", printf(" %09u ", INT_MAX));
	ft_printf(E0M);
	printf("->Result78 %d\n", ft_printf(" %09u ", INT_MAX));

	printf(RED);
	printf("->Result79 %d\n", printf(" %010u ", INT_MIN));
	ft_printf(E0M);
	printf("->Result79 %d\n", ft_printf(" %010u ", INT_MIN));

	printf(RED);
	printf("->Result81 %d\n", printf(" %012u ", LONG_MIN));
	ft_printf(E0M);
	printf("->Result81 %d\n", ft_printf(" %012u ", LONG_MIN));

//	SUBCATEGORY(86, 114, cout << endl << FG_LGRAY << "subcategory: x" << RESET_ALL << endl;)
	printf("->Result87 %d\n", printf(" %01x ", 0));
	printf("->Result87 %d\n", ft_printf(" %01x ", 0));

	printf("->Result88 %d\n", printf(" %02x ", -1));
	printf("->Result88 %d\n", ft_printf(" %02x ", -1));

	printf("->Result89 %d\n", printf(" %04x ", 9));
	printf("->Result89 %d\n", ft_printf(" %04x ", 9));

	printf("->Result90 %d\n", printf(" %01x ", 10));
	printf("->Result90 %d\n", ft_printf(" %01x ", 10));

	printf("->Result91 %d\n", printf(" %02x ", 11));
	printf("->Result91 %d\n", ft_printf(" %02x ", 11));

	printf("->Result92 %d\n", printf(" %03x ", 15));
	printf("->Result92 %d\n", ft_printf(" %03x ", 15));

	printf("->Result93 %d\n", printf(" %04x ", 16));
	printf("->Result93 %d\n", ft_printf(" %04x ", 15));

	printf("->Result94 %d\n", printf(" %05x ", 17));
	printf("->Result94 %d\n", ft_printf(" %05x ", 17));
	
	printf("->Result95 %d\n", printf(" %01x ", 99));
	printf("->Result95 %d\n", ft_printf(" %01x ", 99));

	printf("->Result96 %d\n", printf(" %02x ", 100));
	printf("->Result96 %d\n", ft_printf(" %02x ", 100));

	printf("->Result97 %d\n", printf(" %03x ", 101));
	printf("->Result97 %d\n", ft_printf(" %03x ", 101));

	printf("->Result98 %d\n", printf(" %01x ", -9));
	printf("->Result98 %d\n", ft_printf(" %01x ", -9));

	printf("->Result99 %d\n", printf(" %02x ", -10));
	printf("->Result99 %d\n", ft_printf(" %02x ", -10));

	printf("->Result100 %d\n", printf(" %03x ", -11));
	printf("->Result100 %d\n", ft_printf(" %03x ", -11));

	printf("->Result101 %d\n", printf(" %04x ", -14));
	printf("->Result101 %d\n", ft_printf(" %04x ", -14));

	printf("->Result102 %d\n", printf(" %05x ", -15));
	printf("->Result102 %d\n", ft_printf(" %05x ", -15));

	printf("->Result103 %d\n", printf(" %06x ", -16));
	printf("->Result103 %d\n", ft_printf(" %06x ", -16));

	printf("->Result104 %d\n", printf(" %01x ", -99));
	printf("->Result104 %d\n", ft_printf(" %01x ", -99));

	printf("->Result105 %d\n", printf(" %02x ", -100));
	printf("->Result105 %d\n", ft_printf(" %02x ", -100));

	printf("->Result106 %d\n", printf(" %03x ", -101));
	printf("->Result106 %d\n", ft_printf(" %03x ", -101));
	
	printf("->Result107 %d\n", printf(" %09x ", INT_MAX));
	printf("->Result107 %d\n", ft_printf(" %09x ", INT_MAX));

	printf("->Result108 %d\n", printf(" %010x ", INT_MIN));
	printf("->Result108 %d\n", ft_printf(" %010x ", INT_MIN));

	printf("->Result109 %d\n", printf(" %011x ", LONG_MAX));
	printf("->Result109 %d\n", ft_printf(" %011x ", LONG_MAX));

	printf("->Result110 %d\n", printf(" %012x ", LONG_MIN));
	printf("->Result110 %d\n", ft_printf(" %012x ", LONG_MIN));

	printf("->Result111 %d\n", printf(" %013x ", UINT_MAX));
	printf("->Result111 %d\n", ft_printf(" %013x ", UINT_MAX));

	printf("->Result112 %d\n", printf(" %014x ", ULONG_MAX));
	printf("->Result112 %d\n", ft_printf(" %014x ", ULONG_MAX));

	printf("->Result113 %d\n", printf(" %015x ", ULONG_LONG_MAX));
	printf("->Result113 %d\n", ft_printf(" %015x ", ULONG_LONG_MAX));

	printf("->Result114 %d\n", printf(" %09x %010x %011x %012x %013x %014x %015x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	printf("->Result114 %d\n", ft_printf(" %09x %010x %011x %012x %013x %014x %015x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
/*
//	SUBCATEGORY(115, 143, cout << endl << FG_LGRAY << "subcategory: X" << RESET_ALL << endl;)
	printf(115, printf(" %01X ", 0));
	printf(116, printf(" %02X ", -1));
	printf(117, printf(" %03X ", 1));
	printf(118, printf(" %04X ", 9));
	printf(119, printf(" %01X ", 10));
	printf(120, printf(" %02X ", 11));
	printf(121, printf(" %03X ", 15));
	printf(122, printf(" %04X ", 16));
	printf(123, printf(" %05X ", 17));
	printf(124, printf(" %01X ", 99));
	printf(125, printf(" %02X ", 100));
	printf(126, printf(" %03X ", 101));
	printf(127, printf(" %01X ", -9));
	printf(128, printf(" %02X ", -10));
	printf(129, printf(" %03X ", -11));
	printf(130, printf(" %04X ", -14));
	printf(131, printf(" %05X ", -15));
	printf(132, printf(" %06X ", -16));
	printf(133, printf(" %01X ", -99));
	printf(134, printf(" %02X ", -100));
	printf(135, printf(" %03X ", -101));
	printf(136, printf(" %09X ", INT_MAX));
	printf(137, printf(" %010X ", INT_MIN));
	printf(138, printf(" %011X ", LONG_MAX));
	printf(139, printf(" %012X ", LONG_MIN));
	printf(140, printf(" %013X ", UINT_MAX));
	printf(141, printf(" %014X ", ULONG_MAX));
	printf(142, printf(" %015X ", ULONG_LONG_MAX));
	printf(143, printf(" %09X %010X %011X %012X %013X %014X %015X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
*/
}

void test_fix(void)
{
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	/* %p */
	printf(RED);
	printf("->Result1 %d\n", printf(" |%p| |%p| ", ULONG_MAX, -ULONG_MAX));
	ft_printf(E0M);
	printf("->Result1 %d\n", ft_printf(" |%p| |%p| ", ULONG_MAX, -ULONG_MAX));

	printf(RED);
	printf("->Result2 %d\n", printf(" |%p| |%p| ", 0, 0));
	ft_printf(E0M);
	printf("->Result2 %d\n", ft_printf(" |%p| |%p| ", 0, 0));

	printf(RED);
	printf("->Result3 %d\n", printf(" |%p| |%p| ", LONG_MIN, LONG_MAX));
	ft_printf(E0M);
	printf("->Result3 %d\n", ft_printf(" |%p| |%p| ", LONG_MIN, LONG_MAX));

	printf("\n==== u ====\n\n");
	printf(RED);
	printf("->Result4 %d\n", printf(" |%u| |%u| |%u| |%u| |%u| |%u| |%u|", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	ft_printf(E0M);
	printf("->Result4 %d\n", ft_printf(" |%u| |%u| |%u| |%u| |%u| |%u| |%u|", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));

	printf(RED);
	printf("->Result5 %d\n", printf(" |%u| ", LONG_MIN));
	ft_printf(E0M);
	printf("->Result5 %d\n", ft_printf(" |%u| ", LONG_MIN));

	printf(RED);
	printf("->Result6 %d\n", printf(" |%u| ", 0));
	ft_printf(E0M);
	printf("->Result6 %d\n", ft_printf(" |%u| ", 0));

	/* %mix */
	printf(RED);
	printf("->Result6 %d\n", printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0));
	ft_printf(E0M);
	printf("->Result6 %d\n", ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0));

	printf("\nbehaviour with 0\n");
    printf(" --- Return : %d\n", printf("%d", l));
    printf(" --- Return : %d\n", ft_printf("%d", l));
    printf(" --- Return : %d\n", printf("%0d", l));
    printf(" --- Return : %d\n", ft_printf("%0d", l));
    printf(" --- Return : %d\n", printf("%.d", l));
    printf(" --- Return : %d\n", ft_printf("%.d", l));
    printf(" --- Return : %d\n", printf("%0.d", l));
    printf(" --- Return : %d\n", ft_printf("%0.d", l));

    printf("\nbehaviour with 0 with wodth\n");
    printf(" --- Return : %d\n", printf("%d", l));
    printf(" --- Return : %d\n", ft_printf("%d", l));
    printf(" --- Return : %d\n", printf("%1d", l));
    printf(" --- Return : %d\n", ft_printf("%1d", l));
    printf(" -o- Return : %d\n", printf("%1.d", l));
    printf(" -f- Return : %d\n", ft_printf("%1.d", l));
    printf(" -o- Return : %u\n", printf("%1.u", l));
    printf(" -f- Return : %u\n", ft_printf("%1.u", l));
    printf(" -o- Return : %i\n", printf("%1.i", l));
    printf(" -f- Return : %i\n", ft_printf("%1.i", l));
    printf(" -o- Return : %d\n", printf("%1.1p", 0));
    printf(" -f- Return : %d\n", ft_printf("%1.1p", 0));
    printf(" --- Return : %d\n", printf("%1.1d", l));
    printf(" --- Return : %d\n", ft_printf("%1.1d", l));
    printf(" --- Return : %d\n", printf("%2.d", l));
    printf(" --- Return : %d\n", ft_printf("%2.d", l));
}

void	test_x(void)
{
	printf(RED);
	printf("->Result1 %d\n", printf(" %x ", 0));
	ft_printf(E0M);
	printf("->Result1 %d\n", ft_printf(" %x ", 0));

	printf(RED);
	printf("->Result2 %d\n", printf(" %x ", -1));
	ft_printf(E0M);
	printf("->Result2 %d\n", ft_printf(" %x ", -1));

	printf(RED);
	printf("->Result3 %d\n", printf(" %x ", 1));
	ft_printf(E0M);
	printf("->Result3 %d\n", ft_printf(" %x ", 1));

	printf(RED);
	printf("->Result4 %d\n", printf(" %x ", 9));
	ft_printf(E0M);
	printf("->Result4 %d\n", ft_printf(" %x ", 9));

	printf(RED);
	printf("->Result5 %d\n", printf(" %x ", 10));
	ft_printf(E0M);
	printf("->Result5 %d\n", ft_printf(" %x ", 10));

	printf(RED);
	printf("->Result6 %d\n", printf(" %x ", 11));
	ft_printf(E0M);
	printf("->Result6 %d\n", ft_printf(" %x ", 11));

	printf(RED);
	printf("->Result7 %d\n", printf(" %x ", 15));
	ft_printf(E0M);
	printf("->Result7 %d\n", ft_printf(" %x ", 15));

	printf(RED);
	printf("->Result8 %d\n", printf(" %x ", 16));
	ft_printf(E0M);
	printf("->Result8 %d\n", ft_printf(" %x ", 16));

	printf(RED);
	printf("->Result9 %d\n", printf(" %x ", 17));
	ft_printf(E0M);
	printf("->Result9 %d\n", ft_printf(" %x ", 17));

	printf(RED);
	printf("->Result10 %d\n", printf(" %x ", 99));
	ft_printf(E0M);
	printf("->Result10 %d\n", ft_printf(" %x ", 99));

	printf(RED);
	printf("->Result11 %d\n", printf(" %x ", 100));
	ft_printf(E0M);
	printf("->Result11 %d\n", ft_printf(" %x ", 100));

	printf(RED);
	printf("->Result12 %d\n", printf(" %x ", 101));
	ft_printf(E0M);
	printf("->Result12 %d\n", ft_printf(" %x ", 101));

	printf(RED);
	printf("->Result13 %d\n", printf(" %x ", -9));
	ft_printf(E0M);
	printf("->Result13 %d\n", ft_printf(" %x ", -9));

	printf(RED);
	printf("->Result14 %d\n", printf(" %x ", -10));
	ft_printf(E0M);
	printf("->Result14 %d\n", ft_printf(" %x ", -10));

	printf(RED);
	printf("->Result15 %d\n", printf(" %x ", -11));
	ft_printf(E0M);
	printf("->Result15 %d\n", ft_printf(" %x ", -11));

	printf(RED);
	printf("->Result16 %d\n", printf(" %x ", -14));
	ft_printf(E0M);
	printf("->Result16 %d\n", ft_printf(" %x ", -14));

	printf(RED);
	printf("->Result17 %d\n", printf(" %x ", -15));
	ft_printf(E0M);
	printf("->Result17 %d\n", ft_printf(" %x ", -15));

	printf(RED);
	printf("->Result18 %d\n", printf(" %x ", -16));
	ft_printf(E0M);
	printf("->Result18 %d\n", ft_printf(" %x ", -16));

	printf(RED);
	printf("->Result19 %d\n", printf(" %x ", -99));
	ft_printf(E0M);
	printf("->Result19 %d\n", ft_printf(" %x ", -99));

	printf(RED);
	printf("->Result20 %d\n", printf(" %x ", -100));
	ft_printf(E0M);
	printf("->Result20 %d\n", ft_printf(" %x ", -100));

	printf(RED);
	printf("->Result21 %d\n", printf(" %x ", -101));
	ft_printf(E0M);
	printf("->Result21 %d\n", ft_printf(" %x ", -101));

	printf(RED);
	printf("->Result22 %d\n", printf(" %x ", INT_MAX));
	ft_printf(E0M);
	printf("->Result22 %d\n", ft_printf(" %x ", INT_MAX));

	printf(RED);
	printf("->Result23 %d\n", printf(" %x ", INT_MIN));
	ft_printf(E0M);
	printf("->Result23 %d\n", ft_printf(" %x ", INT_MIN));

	printf(RED);
	printf("->Result24 %d\n", printf(" %x ", LONG_MAX));
	ft_printf(E0M);
	printf("->Result24 %d\n", ft_printf(" %x ", LONG_MAX));

	printf(RED);
	printf("->Result25 %d\n", printf(" %x ", LONG_MIN));
	ft_printf(E0M);
	printf("->Result25 %d\n", ft_printf(" %x ", LONG_MIN));

	printf(RED);
	printf("->Result26 %d\n", printf(" %x ", UINT_MAX));
	ft_printf(E0M);
	printf("->Result26 %d\n", ft_printf(" %x ", UINT_MAX));

	printf(RED);
	printf("->Result27 %d\n", printf(" %x ", ULONG_MAX));
	ft_printf(E0M);
	printf("->Result27 %d\n", ft_printf(" %x ", ULONG_MAX));

	printf(RED);
	printf("->Result28 %d\n", printf(" %x ", ULONG_LONG_MAX));
	ft_printf(E0M);
	printf("->Result28 %d\n", ft_printf(" %x ", ULONG_LONG_MAX));

	printf(RED);
	printf("->Result29 %d\n", printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	ft_printf(E0M);
	printf("->Result29 %d\n", ft_printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
}


int main(void)
{
	test_c();
	test_s();
	test2_s();
	test3_d();
	test4_i();
	test_plus();
	test_zero();
	test_fix();
	test_x();
	return (0);
}
