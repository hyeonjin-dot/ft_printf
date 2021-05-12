/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:26:44 by hyejung           #+#    #+#             */
/*   Updated: 2021/05/12 23:04:12 by jeonghyeo        ###   ########.fr       */
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
		if (ele->num[0] == -1)
			ele->minus = 1;
		else if (ele->minus == 0 && ele->num[1] == -1)
			ele->minus = 2;
	}
	if (ele->num[0] == -1)
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
	{
		write(1, "%", 1);
		return (1);
	}
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
	printf("%d\n", (int)ft_strlen("-2147483648"));
	ft_printf ("%d\n\n",  ft_printf("[%10.6d]", -2147483648));
	printf("%d\n\n", printf("[%10.6d]", -2147483648));
}*/
