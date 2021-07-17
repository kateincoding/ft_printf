/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:29:11 by ciglesia          #+#    #+#             */
/*   Updated: 2021/07/17 09:20:29 by ksoto            ###   ########.fr       */
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

int main(void)
{
//	test_c();
//	test_s();
//	test2_s();
//	test3_d();
	test4_i();
//	test_plus();
	return (0);
}
