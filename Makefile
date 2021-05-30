# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 11:53:24 by hyejung           #+#    #+#              #
#    Updated: 2021/05/30 22:29:11 by jeonghyeo        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM		=	rm -f
NAME	=	libftprintf.a
LIBFT	=	libft

SRCS		= ./ft_printf.c\
			  ./ft_printf_sc.c\
			  ./ft_printf_nbr.c\
			  ./ft_printf_di.c\
			  ./ft_printf_p.c\
			  ./ft_printf_x.c\
			  ./ft_printf_pe.c\
			  ./ft_func.c\
			  ./ft_func2.c

OBJS		= $(SRCS:.c=.o)
INCS		= ./include
RM			= rm -f
LIBC		= ar rc
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -I $(INCS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/libft.a $(NAME)
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
