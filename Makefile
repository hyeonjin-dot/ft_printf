# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 11:53:24 by hyejung           #+#    #+#              #
#    Updated: 2021/03/04 11:55:07 by hyejung          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM		=	rm -f
NAME	=	libftprintf.a


all		:	$(NAME)

clean	:
	$(RM) $(OBJS) $(OBJS_B)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

bonus	:	$(OBJS) $(OBJS_B)
	$(LIB) $(NAME) $(OBJS) $(OBJS_B)

.PHONY	:	all clean fclean re bonus
