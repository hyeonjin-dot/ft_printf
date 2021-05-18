/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:27:54 by hyejung           #+#    #+#             */
/*   Updated: 2021/05/15 20:51:20 by jeonghyeo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	t_elements
{
	int		minus;
	int		num[2];
	int		dot;
	int		zero;
	int		len;
	char	form;
}	t_ele;

int		printf_di(va_list ap, t_ele *ele);
int		printf_u(va_list ap, t_ele *ele);
int		printf_x(va_list ap, t_ele *ele);
int		printf_p(va_list ap, t_ele *ele);
int		printf_s(va_list ap, t_ele *ele);
int		printf_c(va_list ap, t_ele *ele);
int		printf_pe(va_list ap, t_ele *ele);
int		ft_printf(const char *str, ...);
int		check_form(char c);
void	dot_2(t_ele *ele);

#endif
