/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 22:37:47 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/15 05:32:45 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** validate_operator - validate if it is an operator
** @op: operator to evaluate
** c = char
** s = string
** p = pointer
** d = decimal
** i = integer
** u = unsigned numbers
** xX = hexadecimal
** Return: 1 if is positive; 0 if is negative
*/

int	validate_operator(char op)
{
	return (ft_chrcount("diouxXcspf%", op) > 0);
}

/*
** validate_modifier- validate if it is a flag
** @flag: flag to evaluate
** Return: 1 if is positive; 0 if is negative
*/

int	validate_modifier(const char *format, int i)
{
	if (ft_chrcount("hlL", format[i]) > 0)
	{
		i++;
		if (format[i] == 'h' || format[i] == 'l')
			i++;
	}
	return (i);
}

/*
** validate_flag - validate if it is a flag
** @flag: flag to evaluate
** - A minus sign `-' which specifies left adjustment of the
** output in the indicated field;
** 0 A zero `0' character indicating that zero-padding should be
** used rather than blank-padding.
** A `-' overrides a `0' if both are used;
** . precision which specifies the number of digits to appear after the decimal
** point* width - A field width or precision may be `*' instead of a digit
** string. In this case an argument supplies the field width or precision.
** Return: 1 if is positive; 0 if is negative
*/

int	validate_flag(const char flag)
{
	return (ft_chrcount("-0.*# +", flag) > 0);
}

int	validate_only_flag(const char flag)
{
	return (ft_chrcount("-0# +", flag) > 0);
}

/*
** valid_operator_with_flag - validate
** %[$][flags][width][.precision][length modifier]conversion
** %[$][flags][0 - 9][. + [0-9]][length modifier]conversion
** %[$][flags]['*'][. + '*'][length modifier]conversion
** types of error:
** %[$][flags]['*'+ [0-9]][. + [0-9] '*'][length modifier]conversion
** %[$][flags][[0-9]'*'][. + '*' [0-9][length modifier]conversion
*/

int	valid_operator_flag_modifier(const char *format, int i)
{
	int	result;

	result = 0;
	while (validate_flag(format[i]))
		i++;
	while ('0' <= format[i] && format[i] <= '9')
		i++;
	if (format[i] == '.')
	{
		i++;
		while ('0' <= format[i] && format[i] <= '9')
			i++;
		if (format[i] == '*')
			i++;
	}
	i = validate_modifier(format, i);
	result = validate_operator(format[i]);
	return (result);
}
