#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int a = 5;
    int i = 7;
    char h = 'k';

/*
    ft_printf("hola\n");
    case resolved
    ft_printf("% 5 d\n", 29);
    printf("% 5 d\n", 29);
    printf("-----------\n");
*/
/* ---------------- test %c -----------------*/
/*
    ft_printf("prueba %c\n", 'k');
    printf("prueba %c\n", 'k');
    ft_printf("prueba %0c\n", h);
    printf("prueba %0c\n", h);
    ft_printf("prueba %-2c\n", h);
    printf("prueba %-2c\n", h);
*/
/* ---------------- test %s -----------------*/
/*
    ft_printf("prueba %s\n", "kate");
    printf("prueba %s\n", "kate");
    ft_printf("prueba %0s\n", "kate");
    printf("prueba %0s\n", "kate");
    ft_printf("prueba %-2s\n", "kate");
    printf("prueba %-2s\n", "kate");
*/

/* ---------------- test %d -----------------*/

    ft_printf("prueba %d\n", 42);
    printf("prueba %d\n", 42);
    ft_printf("prueba %1.0d\n", 123456789);
    printf("prueba %1.0d\n", 123456789);
    ft_printf("prueba %7d\n", 42);
    printf("prueba %7d\n", 42);
    ft_printf("prueba %7.0d.\n", 42);
    printf("prueba %7.0d.\n", 42);
    ft_printf("prueba %-7.0d.\n", 42);
    printf("prueba %-7.0d.\n", 42);
    ft_printf("%   5d\n", 29);
    printf("%   5d\n", 29);
    printf("-----------\n");

    ft_printf("% 5wd\n", 2, 9);
    printf("% 5wd\n", 2, 9);
    
    printf("-----------\n");
    ft_printf("%   5wd\n", 2, 9);
    printf("%   5wd\n", 2, 9);
    // ft_printf("%*d\n", 5, 4);
    // printf("%*d\n", 5, 4);
    // ft_printf("%d\n", 2, 9);
    // printf("%d\n", 2, 9);
    ft_printf("%-6d\n", 29);
    printf("%-6d\n", 29);
    ft_printf("%.5d\n", 29);
    printf("%.5d\n", 29);
    ft_printf("'%-6.5d'\n", 29);
    printf("'%-6.5d'\n", 29);

 //   ft_printf("% 10.21f\n", 29.1234);
 //   printf("% 10.21f\n", 29.1234);
    printf("-----------\n");

    /*
    case linux done, case mac is different -> changed
    ft_printf("%  *.*  f hola\n", 2, 1, 29.1234);
    printf("%  *.*  f hola\n", 2, 1, 29.1234);
    printf("-----------\n"); */

    /*
    ft_printf("% *.* \n", 2, 1, 29.1234);
    printf("% *.* \n", 2, 1, 29.1234);
    printf("-----------\n"); */

/*    printf("'%5.3f'\n", 29.12345);
    printf("'%-0*.*f'\n", 10, 2, 2.12345);
    printf("'%10.5f'\n", 29.1);
    printf("'%-00000--*i'\n", 10, 2);
    printf("'%-0-0-000--*i'\n", 10, 2);
    printf("'%0 *i'\n", 10, 2);
    printf("'%-0*.*f'\n", 10, 2, 2.12345);
    printf("'%-0  *.*f'\n", 10, 2, 2.12345);
    printf("'%-0*.*f'\n", 10, 2, 2.12345);
    printf("'%-0*.*f'\n", 10, 2, 2.12345);
    printf("'%-0*.  *f'\n", 10, 2, 2.12345);
    printf("%   d hola\n", 29);
    printf("%04d\n", -15);
    printf("%.4d\n", -15);
    printf("'%-00000-----*i',' %--0.*d',' %0-0-0-0-0.*d',' %-0-0-0-0-.*d',' %.*d'\n", a, i, a, i, a, i, a, i, a, i);
    */
    return (0);
}
