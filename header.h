#ifndef HEADER_H
#	define HEADER_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_strlen(const char *str);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

#endif
