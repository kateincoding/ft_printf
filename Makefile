# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksoto <ksoto@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/27 13:15:05 by ciglesia          #+#    #+#              #
#    Updated: 2021/07/21 18:55:33 by ciglesia         ###   ########.fr        #
#    Updated: 2021/07/09 12:00:04 by ksoto            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

#***************** LIB ********************#
# General
INC			=	./includes/

# Lib
LIB			=	./libft/
INCFT		=	./libft/include/

INCLUDE		=	-I $(INC) -I $(INCFT)

#***************** DIR ********************#

DIRSRC		=	./srcs/
DIRFT		=	$(LIB)/src/

#***************** SRC ********************#

SRC			=	stack_manipulation.c ft_printf.c handle_format.c validate_format.c select_functions.c ft_conversion_cs.c ft_conversion_diu.c ft_conversion_xX.c ft_final_width_calculation.c ft_conversion_p.c ft_flags_cs.c ft_flags_xX.c ft_flags_p.c ft_flags_diu.c set_flags_structure.c ft_width_diu.c ft_vfprintf.c

SRCS		=	$(SRC)

#***************** DEPS *******************#

DIROBJ		=	./depo/

OAUX		=	$(SRCS:%=$(DIROBJ)%)
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

bonus	:		$(NAME)

fclean	:		clean
				@$(RM) $(NAME)
				@(cd $(LIB) && $(MAKE) fclean)
				@$(ECHO) $(BOLD)$(RED)'> Remove executable'$(E0M)

re		:		fclean all

ftlib	:
				@(cd $(LIB) && $(MAKE))

test	:
				$(CC) $(INCLUDE) test.c libftprintf.a

debug	:
				$(CC) -g $(INCLUDE) test.c libftprintf.a $(LIB)/libft.a

.PHONY	:		all bonus clean fclean re ftlib

-include $(DEPS)
