#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
// # include "../libft/libft.h"
# include <stdio.h>

/*
** struct s_fields - Struct for fields of the future printed string for each argv
**
** @fd: file descriptor
** @op: Parameter that represents possible printf operators (%s, %c, %i, ...)
** @f: function associated with the before operator
** @length: output
**
** flags: ’-0.*’
** @minus: [-] Left-justify within the given field width; Right
** justification is the default
** @zero: [0] Left-pads the number with zeroes (0) instead of spaces
** when padding is specified
** @width: The additional integer value argument preceding the argument
** that has to be formatted determinates the max lenght
** @wildcart:[*]
** @precision: [.] The additional integer value argument preceding the argument
** that has to be formatted.
*/

typedef struct s_fields
{
	char	*format;
	int		idx;
	int		fd;
	char	op;
	int		lenght;
	int		minus;
	int		zero;
	int		width;
	int		final_width;
	int		wildcard;
	int		precision;
	int		hashtag;
	int		space;
	int		plus;
	int		len;
	int		break_flag;
}	t_fields;

/*
** struct s_func - Struct for possible operators and connect with their function
**
** @op: Parameter that represents possible printf operators (cspdiuxX%):
** %c print a single character
** %s print a string of characters
** %d print a decimal (base 10) number
** %i print an integer in base 10
** %u print an unsigned decimal (base 10) number
** %x print a number in hexidecimal (base 16)
** %% print a percent sign (\% also works)
**
** @f: The function associated
*/

typedef struct s_func
{
	char	op;
	int		(*f)(va_list);
}	t_func;

/*
** ft_printf: call printf functions
*/

int		ft_printf(const char *format, ...);
int		ft_dprintf(const int fd, const char *format, ...);
int		ft_vfprintf(int fd, const char *format, va_list args);

/*
** validate operators and flags
*/

int		valid_operator_flag_modifier(const char *format, int i);
int		validate_operator(char op);
int		validate_flag(const char flag);

/*
** global structure to handle width, flag and precision
*/
t_fields	*str;

void	initialize_stack(const char *inputs, int fd);
void	finalize_stack(void);

/*
** create structure for each argv
*/

void	set_flags(void);
void	restart_flags(void);
int		validate_only_flag(const char flag);
void	set_width(va_list args_list);
void	set_precision(va_list args_list);

int		select_function(va_list list);

int		print_before(void);
int		print_format(va_list args_list);
void	print_after(void);
void	calculate_format_width(void);

/*
** conversion operators function
*/

int		print_char(va_list lista);
int		print_str(va_list lista);
//int print_rev_str(va_list lista);
//int print_Str_Ascii(va_list arg);

/* print functions : type numbers */
int		putN(unsigned int n, unsigned int b, char *nums);
int		print_int(va_list lista);
int		print_unsigned(va_list lista);

/* print bases */
int		print_hex(va_list lista);
int		print_upper_hexadecimal(va_list lista);

/* print pointer */
int		print_ptr(va_list lista);

/*
** libft
*/

int		ft_putchar(char c);
int		ft_putchar_fd(char c, int fd);
int		ft_chrcount(char const *s, char c);
void	*ft_memalloc(size_t size);
int		ft_atoi(char *str);
int		ft_putnbr(int n);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char const *s, int fd);
size_t	ft_strlen(const char *s);

# if __APPLE__
#  define IS_MACOS 1
# else
#  define IS_MACOS 0
# endif

#endif
