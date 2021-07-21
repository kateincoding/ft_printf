/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:52:12 by ksoto             #+#    #+#             */
/*   Updated: 2021/07/16 09:03:29 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

/*
**	stdlib
*/

int		ft_atoi(char *str);

/*
**	stdio
*/

int		ft_putchar(char c);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putnbr(int n);
int		ft_putstr_fd(const char *s, int fd);

/*
**	strings
*/

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memalloc(size_t size);
int		ft_chrcount(const char *s, char c);
size_t	ft_strlen(const char *s);
// char    *ft_itoa(int n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);

#endif
