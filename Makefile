# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 11:53:24 by hyejung           #+#    #+#              #
#    Updated: 2021/04/30 18:52:48 by hyejung          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM		=	rm -f
NAME	=	libftprintf.a
LIBFT	=	libft
LIBFT_A	=	libft.a

SRCS		= ./ft_printf.c\
			  ./ft_printf_sc.c\
			  ./ft_printf_nbr.c\
			  ./ft_printf_p.c\
			  ./ft_printf_x.c\
			  ./ft_func.c
OBJS		= $(SRCS:.c=.o)
INCS		= .
RM			= rm -f
LIBC		= ar rc
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_A) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

all		:	$(NAME)

clean	:
	$(RM) $(OBJS) $(OBJS_B)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

bonus	:	$(OBJS) $(OBJS_B)
	$(LIB) $(NAME) $(OBJS) $(OBJS_B)

.PHONY	:	all clean fclean re bonus
