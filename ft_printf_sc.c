/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:27:32 by hyejung           #+#    #+#             */
/*   Updated: 2021/05/15 18:52:10 by jeonghyeo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		printf_s_dot(char *tmp, t_ele *ele)
{
	int		i;
	int		len;

	len = ft_strlen(tmp);
	i = ele->num[0];
	if (ele->dot == 1 && ele->num[1] <= 0)
	{
		while (ele->num[0]-- > 0)
			write(1, " ", 1);
		return (i);
	}
	else
	{
		if (ele->num[0] < len && ele->num[0] > 0)
		{
			write(1, tmp, ele->num[0]);
			return (ele->num[0]);
		}
		else if (ele->num[0] <= 0)
			return (0);
		else
		{
			write(1, tmp, len);
			return ((int)len);
		}
	}
}

int		printf_s_minus(va_list ap, t_ele *ele)
{
	char	*tmp;
	int		len;
	int		i;

	tmp = va_arg(ap, char*);
	len = ft_strlen(tmp);
	i = ele->num[0];
	if ((ele->dot == 1 && ele->num[1] <= 0) || ele->dot == 2)
		return (printf_s_dot(tmp, ele));
	ele->num[0] = ele->num[0] - len;
	write(1, tmp, len);
	while ((ele->num[0])-- > 0)
		write(1, " ", 1);
	if (i < (int)len)
		return ((int)len);
	else
		return (i);
}

int		printf_s(va_list ap, t_ele *ele)
{
	char	*tmp;
	int		len;
	int		i;

	if (ele->minus % 2 == 1)
		return (printf_s_minus(ap, ele));
	i = ele->num[0];
	tmp = va_arg(ap, char*);
	if (tmp == 0)
		tmp = "(null)";
	len = ft_strlen(tmp);
	if ((ele->dot == 1 && ele->num[1] <= 0) || ele->dot == 2)
		return (printf_s_dot(tmp, ele));
	if (ele->dot == 1 && len > ele->num[1] && ele->minus == 0)
		len = ele->num[1];
	if (ele->minus == 2)
		ele->num[1] = len;
	ele->num[0] = ele->num[0] - len;
	while (ele->num[0]-- > 0)
	{
		if (ele->zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
	write(1, tmp, len);
	if (i < (int)len)
		return ((int)len);
	else
		return (i);
}

int		printf_c(va_list ap, t_ele *ele)
{
	char	tmp;
	int		i;

	tmp = va_arg(ap, int);
	i = ele->num[0];
	if (ele->dot == 2 && ele->num[0] != -1)
		write(1, &tmp, 1);
	if (ele->minus % 2 == 1)
		write(1, &tmp, 1);
	while (ele->num[0] - 1 > 0)
	{
		if (ele->zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		ele->num[0]--;
	}
	if (ele->minus == 0)
		write(1, &tmp, 1);
	if (i > 1)
		return (i);
	else
		return (1);
}
