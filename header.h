#ifndef HEADER_H
#	define HEADER_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"


typedef struct  s_elements
{
    int		minus;
    int		num[2];
    int		dot;
    int		zero;
	char	form;
}   t_ele;

int		printf_di(va_list ap, t_ele ele);
int		printf_u(va_list ap, t_ele ele);
int		ft_printf(const char *str, ...);

#endif
