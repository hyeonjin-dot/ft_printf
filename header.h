/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:27:54 by hyejung           #+#    #+#             */
/*   Updated: 2021/05/30 21:12:55 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct	s_ele
{
	int			minus;
	int			num[2];
	int			dot;
	int			zero;
	int			len;
	char		form;
}				t_ele;

t_ele			reset_elements(void);
t_ele			new_elements(int len);
int				printf_di(va_list ap, t_ele *ele);
int				printf_u(va_list ap, t_ele *ele);
int				printf_x(va_list ap, t_ele *ele);
int				printf_p(va_list ap, t_ele *ele);
int				printf_s(va_list ap, t_ele *ele);
int				printf_c(va_list ap, t_ele *ele);
int				printf_pe(t_ele *ele);
int				ft_printf(const char *str, ...);
int				check_form(char c);
void			dot_2(t_ele *ele);
void			numleszero(int *len, int *j);
int				numiszero(int i, t_ele *ele);
void			nbr_len_minus(int len, t_ele *ele);
void			nbr_len_plus(int num, int len, t_ele *ele);
int				return_minus(int i, int j, int len, t_ele *ele);
int				return_plus(int i, int j, int len, t_ele *ele);

#endif
