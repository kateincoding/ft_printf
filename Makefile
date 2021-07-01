# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/27 13:15:05 by ciglesia          #+#    #+#              #
#    Updated: 2021/07/01 05:57:34 by ksoto            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

#***************** LIB ********************#
# General
INC			=	./includes/

INCLUDE		=	-I $(INC)

# Lib
LIB			=	./libft/

#***************** DIR ********************#

DIRSRC		=	./srcs/

#***************** SRC ********************#

SRC			=	stack_manipulation.c ft_printf.c handle_format.c validate_format.c select_functions.c ft_conversion_cs.c ft_conversion_diu.c ft_conversion_xX.c

#***************** DEPS *******************#

DIROBJ		=	./depo/

OAUX		=	$(SRC:%=$(DIROBJ)%)
DEPS		=	$(OAUX:.c=.d)
OBJS		=	$(OAUX:.c=.o)

ifdef FLAGS
	ifeq ($(FLAGS), no)
CFLAGS		=
	endif
	ifeq ($(FLAGS), debug)
CFLAGS		=	-Wall -Wextra -Werror -ansi -pedantic -g -fPIC
	endif
else
CFLAGS		=	-Wall -Wextra -Werror -fPIC
endif

CC			=	/usr/bin/gcc
RM			=	/bin/rm -f
ECHO		=	/bin/echo -e
BOLD		=	"\e[1m"
BLINK		=	"\e[5m"
RED			=	"\e[38;2;255;0;0m"
GREEN		=	"\e[92m"
BLUE		=	"\e[34m"
YELLOW		=	"\e[33m"
E0M			=	"\e[0m"

#************************ DEPS COMPILATION *************************

%.o		:		../$(DIRSRC)/%.c
				@printf $(GREEN)"Generating libftprintf objects... %-33.33s\r" $@
				@$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

#************************ MAIN COMPILATION *************************

$(NAME)	:		ftlib $(OBJS)
				@$(ECHO)
				@ar rc $(NAME) $(OBJS)
				@ranlib $(NAME)
				@$(ECHO) $(BOLD)$(GREEN)'> Compiled'$(E0M)

clean	:
				@($(RM) $(OBJS))
				@($(RM) $(DEPS))
				@(cd $(LIB) && $(MAKE) clean)
				@$(ECHO) $(BOLD)$(RED)'> Directory cleaned'$(E0M)

all		:		$(NAME)

fclean	:		clean
				@$(RM) $(NAME)
				@(cd $(LIB) && $(MAKE) fclean)
				@$(ECHO) $(BOLD)$(RED)'> Remove executable'$(E0M)

re		:		fclean all

ftlib	:
				@(cd $(LIB) && $(MAKE))

test	:
				$(CC) $(INCLUDE) main.c libftprintf.a $(LIB)/libft.a 

debug	:
				$(CC) -g $(INCLUDE) main.c libftprintf.a $(LIB)/libft.a 

.PHONY	:		all clean fclean re ftlib

-include $(DEPS)
