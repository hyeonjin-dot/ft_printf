/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:26:44 by hyejung           #+#    #+#             */
/*   Updated: 2021/05/16 17:58:44 by jeonghyeo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_ele	reset_elements(void)
{
	t_ele	ele;

	ele.minus = 0;
	ele.num[0] = -1;
	ele.num[1] = -1;
	ele.dot = 0;
	ele.zero = 0;
	ele.form = 'q';
	ele.len = 0;
	return (ele);
}

t_ele	new_elements(int len)
{
	t_ele   ele;

	ele.minus = 0;
	ele.num[0] = -1;
	ele.num[1] = -1;
	ele.dot = 0;
	ele.zero = 0;
	ele.form = 'q';
	ele.len = len;
	return (ele);
}

void	star(va_list ap, t_ele *ele)
{
	int	num;

	num = va_arg(ap, int);
	if (num < 0)
	{
		num = -num;
		if (ele->num[0] <= 0 && ele->dot == 0)
			ele->minus = 3;
		else if (ele->minus == 0 && ele->num[1] == -1)
			ele->minus = 2;
		else if (ele->minus % 2 == 1 && ele->num[0] != -1)
			ele->minus = 5;
	}
	if ((ele->num[0] == 0 && ele->dot == 0) || ele->num[0] == -1)
		ele->num[0] = num;
	else
		ele->num[1] = num;
}

int		printf_form(va_list ap, t_ele *ele)
{
	if (ele->form == 's')
		return (printf_s(ap, ele));
	if (ele->form == 'd' || ele->form == 'i')
		return (printf_di(ap, ele));
	if (ele->form == 'c')
		return (printf_c(ap, ele));
	if (ele->form == 'u')
		return (printf_u(ap, ele));
	if (ele->form == 'x' || ele->form == 'X')
		return (printf_x(ap, ele));
	if (ele->form == 'p')
		return (printf_p(ap, ele));
	else
		return (printf_pe(ap, ele));
}

int		ft_check(char *str, int i, t_ele *ele, va_list ap)
{
	while (check_form(str[i]) == 0 && str[i] != '%')
	{
		if (str[i] == '*')
			star(ap, ele);
		else if (str[i] == '-')
			ele->minus = 1;
		else if (str[i] >= '0' && str[i] <= '9')
		{
			if (str[i] == '0')
				ele->zero++;
			if (ele->num[0] == -1)
				(ele->num[0] = ft_atoi(&str[i]));
			else
				(ele->num[1] = ft_atoi(&str[i]));
			while (str[i] >= '0' && str[i] <= '9')
				i++;
			i--;
		}
		else if (str[i] == '.')
			ele->dot = (ele->num[0] == -1 ? 2 : 1);
		i++;
	}
	ele->form = str[i];
	ele->len = ele->len + printf_form(ap, ele);
	return (i);
}

int		ft_printf(const char *str, ...)
{
	va_list ap;
	t_ele	ele;
	int     i;
	int		len;

	i = 0;
	va_start(ap, str);
	ele = reset_elements();
	while (str[i])
	{
		if (str[i] == '%')
		{
			len = ele.len;
			ele = new_elements(len);
			i++;
			i = ft_check((char*)str, i, &ele, ap);
			if (ele.num[0] == -2)
				ele.num[0] = -1;
			if (ele.num[1] == -2)
				ele.num[1] = -1;
		}
		else
		{
			write(1, &str[i], 1);
			ele.len++;
		}
		i++;
	}
	return (ele.len);
}

//main 함수
// 해야 할 것 : minus == 2 의 경우 처리하기 (%d)
/*int	main()
{
    int     a = -4;
    int     b = 0;
    char    c = 'a';
    int     d = 2147483647;
    int     e = -2147483648;
    int     f = 42;
    int     g = 25;
    int     h = 4200;
    int     i = 8;
    int     j = -12;
    int     k = 123456789;
    int     l = 0;
    int     m = -12345678;
    char    *n = "abcdefghijklmnop";
    char    *o = "-a";
    char    *p = "-12";
    char    *q = "0";
    char    *r = "%%";
    char    *s = "-2147483648";
    char    *t = "0x12345678";
    char    *u = "-0";
	int		nb = 70;

	printf(" --- Return : %d\n", printf("%-1.i, %-1.d, %-1.d, %-1.d, %-1.d, %-1.d, %-1d, %-1d", i, j, k, l, m, c, e, d));
	ft_printf(" --- Return : %d\n", ft_printf("%-1.i, %-1.d, %-1.d, %-1.d, %-1.d, %-1.d, %-1d, %-1d", i, j, k, l, m, c, e, d));
}*/

/*int	main()
{
	printf("%d\n\n", printf("%---2s", -2));
	ft_printf("%d\n\n", ft_printf("%s", NULL));
 	// printf(" --- Return : %d\n", printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s", NULL, NULL
 NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL));
   //ft_printf(" --- Return : %d\n", ft_printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s", NULL, NULL
 NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL));
}*/
