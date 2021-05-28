/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:26:44 by hyejung           #+#    #+#             */
/*   Updated: 2021/05/28 19:39:36 by jeonghyeo        ###   ########.fr       */
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
		else if (ele->minus == 1 && ele->num[0] == -1)
			ele->minus = 7;
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
	if (ele->form == '%')
		return (printf_pe(ele));
	else
		return (0);
}

int		ft_check(char *str, int i, t_ele *ele, va_list ap)
{
	while (check_form(str[i]) == 0 && str[i] != '%')
	{
		if (str[i] == '*')
			star(ap, ele);
		else if (str[i] == '-')
		{
			ele->minus = 1;
			if (ele->num[0] != -1)
				ele->num[0] = -1;
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			if (str[i] == '0')
				ele->zero = 1;
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



/*int	main()
{
printf(" --- Return : %d\n", printf("%2.9x", 0));//512
ft_printf(" --- Return : %d\n", ft_printf("%2.9x", 0));//512
printf(" --- Return : %d\n", printf(""));//513
ft_printf(" --- Return : %d\n", ft_printf(""));//513

 }*/
