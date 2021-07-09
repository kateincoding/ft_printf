#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
//    int a = 5;
//    int i = 7;
//    char h = 'k';

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

/* check it 
    "%06d", -42  =-00042
    "%.6d", -42   =-000042
 */
/*
    ft_printf("prueba %   d\n", 42);
    printf("prueba %   d\n", 42);

    ft_printf("prueba %1.0d\n", 123456789);
    printf("prueba %1.0d\n", 123456789);
    ft_printf("prueba %7d\n", 42);
    printf("prueba %7d\n", 42);

    ft_printf("prueba %7.0d.\n", 42);
    printf("prueba %7.0d.\n", 42);
    ft_printf("prueba %-7.0d.\n", 42);
    printf("prueba %-7.0d.\n", 42);
    printf("-----------\n");
    printf("\n");
    ft_printf("%   5d\n", 29);
    printf("%   5d\n", 29);


    printf("-----------\n");

    ft_printf("% 5wd\n", 2, 9);
    printf("% 5wd\n", 2, 9);
    
    printf("-----------\n");
    ft_printf("%   3wd\n", 2, 9);
    printf("%   3wd\n", 2, 9);

    ft_printf("%-6d\n", 29);
    printf("%-6d\n", 29);
    ft_printf("%.5d\n", 29);
    printf("%.5d\n", 29);
*//*
    ft_printf("'%  6.3d'\n", 29);
    printf("'%  6.3d'\n", 29);
    ft_printf("ft_printf-> '%6.0d'\n", 29);
    printf("printf   -> '%6.0d'\n", 29);
    ft_printf("ft_printf-> '%  -6.3d'\n", 29);
    printf("printf   -> '%  -6.3d'\n", 29);
    ft_printf("'%-1.8d'\n", 29);
    printf("'%-1.8d'\n", 29);
    ft_printf("'%-15.3d'\n", 29);
    printf("'%-15.3d'\n", 29);
*//*
    printf("------wildcard-----\n");
    ft_printf("%*d\n", 5, 4);
    printf("%*d\n", 5, 4);
    ft_printf("%d\n", 2, 9);
    printf("%d\n", 2, 9);
    printf("-----------\n");

    /* ---------------- test %i -----------------*/
/*
    ft_printf("prueba %u\n", -42);
    printf("prueba %u\n", -42);
    ft_printf("prueba %   u\n", 42);
    printf("prueba %   u\n", 42);
    ft_printf("prueba %1.0i\n", 123456789);
    printf("prueba %1.0i\n", 123456789);
    ft_printf("prueba %7i\n", 42);
    printf("prueba %7i\n", 42);

    ft_printf("prueba %7.0i.\n", 42);
    printf("prueba %7.0i.\n", 42);
    ft_printf("prueba %-7.0i.\n", 42);
    printf("prueba %-7.0i.\n", 42);
*/
/*
    printf("-----------\n");
    printf("\n");
    ft_printf("%   5i\n", 29);
    printf("%   5i\n", 29);

    printf("-----------\n");
*/
/*
    ft_printf("% 5wi\n", 2, 9);
    printf("% 5wi\n", 2, 9);
    
    printf("-----------\n");
    ft_printf("%   3wi\n", 2, 9);
    printf("%   3wi\n", 2, 9);

    ft_printf("%-6i\n", 29);
    printf("%-6i\n", 29);
    ft_printf("%.5i\n", 29);
    printf("%.5i\n", 29);
    ft_printf("'%-6.8i'\n", 29);
    printf("'%-6.8i'\n", 29);

    printf("------wildcard-----\n");
    ft_printf("%*i\n", 5, 4);
    printf("%*i\n", 5, 4);
    ft_printf("%i\n", 2, 9);
    printf("%i\n", 2, 9);
*/
    /* ---------------- test %u -----------------*/
/*
    ft_printf("prueba %u\n", -42);
    printf("prueba %u\n", -42);
    ft_printf("prueba %   u\n", 42);
    printf("prueba %   u\n", 42);

    ft_printf("prueba %1.0u\n", 123456789);
    printf("prueba %1.0u\n", 123456789);
    ft_printf("prueba %7u\n", 42);
    printf("prueba %7u\n", 42);
    ft_printf("prueba %7.0u.\n", 42);
    printf("prueba %7.0u.\n", 42);
    ft_printf("prueba %-7.0u.\n", 42);
    printf("prueba %-7.0u.\n", 42);
    ft_printf("prueba %-7.0u.\n", 42);
    printf("prueba %-7.0u.\n", 42);
    printf("-----------\n");
    printf("\n");
    ft_printf("%   5u\n", 29);
    printf("%   5u\n", 29);

    printf("-----------\n");

    ft_printf("% 5wu\n", 2, 9);
    printf("% 5wu\n", 2, 9);
    
    printf("-----------\n");
    ft_printf("%   3wu\n", 2, 9);
    printf("%   3wu\n", 2, 9);

    ft_printf("%-6u\n", 29);
    printf("%-6u\n", 29);
    ft_printf("%.5u\n", 29);
    printf("%.5u\n", 29);
    ft_printf("'%-6.8u'\n", 29);
    printf("'%-6.8u'\n", 29);

    printf("------wildcard-----\n");
    ft_printf("%*u\n", 5, 4);
    printf("%*u\n", 5, 4);
    ft_printf("%u\n", 2, 9);
    printf("%u\n", 2, 9);
*/
/*
    printf("********************************************\n");
    printf("*************** TESTS x HEXA ***************\n");
    printf("********************************************\n");

    printf("**** case 0: %%x %%Xvalues given: 42, 42 **\n");
    printf ("sysprintf    ~ %x %X\n", 42, 42);
    ft_printf ("ft_printf    ~ %x %X\n\n", 42, 42);

    printf ("sysprintf    ~ %-x %-X\n", 42, 42);
    ft_printf ("ft_printf    ~ %-x %-X\n\n", 42, 42);

    printf("**** case 1: %%x %%X values given: 1561, 1561 **\n");
    printf ("sysprintf    ~ %x %X\n", 1561, 1561);
    ft_printf ("ft_printf    ~ %x %X\n\n", 1561, 1561);

    printf("**** case 2: %%x valuee given: 8729171 **\n");
    printf ("sysprintf    ~ %   x.\n", 8729171);
    ft_printf ("ft_printf    ~ %   x.\n\n", 8729171);

    printf ("sysprintf    ~ %   -x.\n", 8729171);
    ft_printf ("ft_printf    ~ %   -x.\n\n", 8729171);

    printf ("sysprintf    ~ %2x.\n", 8729171);
    ft_printf ("ft_printf    ~ %2x.\n\n", 8729171);

    printf ("sysprintf    ~ %2.10x.\n", 8729171);
    ft_printf ("ft_printf    ~ %2.10x.\n\n", 8729171);

    printf ("sysprintf    ~ %15x.\n", 8729171);
    ft_printf ("ft_printf    ~ %15x.\n\n", 8729171);

    printf ("sysprintf    ~ %-15.3x.\n", 8729171);
    ft_printf ("ft_printf    ~ %-15.3x.\n\n", 8729171);

    printf ("sysprintf    ~ %-1.15x.\n", 8729171);
    ft_printf ("ft_printf    ~ %-1.15x.\n\n", 8729171);
*/

//   ft_printf("% 10.21f\n", 29.1234);
//   printf("% 10.21f\n", 29.1234);
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

    printf("********************************************\n");
    printf("*************** TESTS x PTR ****************\n");
    printf("********************************************\n");

    char *a = "mmmmmmmm";
	char **p = &a;

    printf("**** case 0: %%p value given: a **\n");
    printf ("sysprintf    ~ %p\n", a);
    ft_printf ("ft_printf    ~ %p\n\n", a);

    printf("\n**** case 1: %%p value given: NULL **\n");
    printf ("sysprintf    ~ %p\n", NULL);
    ft_printf ("ft_printf    ~ %p\n\n", NULL);

    printf("**** case 2: %%p value given: p **\n");
    printf ("sysprintf    ~ %p.\n", p);
    ft_printf ("ft_printf    ~ %p.\n\n", p);

    ft_printf("**** case 3: %%5p value given: 0 **\n");
    printf ("sysprintf    ~ %5p.\n", 0);
    ft_printf ("ft_printf    ~ %5p.\n\n", 0);

    printf("**** case 4: %%p value given: -20p **\n");
    printf ("bytes_o: %d\n", printf ("sysprintf    ~ %-20p.\n", p));
    ft_printf ("bytes_f: %d\n\n", ft_printf ("ft_printf    ~ %-20p.\n", p));

    printf("**** case 5: %%*.p value given NULL\n");
    printf("bytes_o: %d\n\n", printf ("%*.p\n",NULL));
    ft_printf ("bytes_f: %d\n\n", ft_printf ("%*.p\n", NULL));

    printf("**** case 6: %%*5.p value given NULL\n");
    printf("bytes_o: %d\n\n", printf ("%*5.p\n",NULL));
    ft_printf ("bytes_f: %d\n\n", ft_printf ("%*5.p\n", NULL));

    printf("**** case 7: %%2.9p value given 1234\n");
    printf("bytes_o: %d\n\n", printf ("%2.15p\n",1234));
    ft_printf ("bytes_f: %d\n\n", ft_printf ("%2.15p\n", 1234));

    printf("**** case 8: %%.5p value given NULL\n");
    printf("bytes_o: %d\n\n", printf ("%.5p\n",0));
    ft_printf ("bytes_f: %d\n\n", ft_printf ("%.5p\n", 0));

    return (0);
}
