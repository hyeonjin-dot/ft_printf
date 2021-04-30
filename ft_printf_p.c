/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:27:14 by hyejung           #+#    #+#             */
/*   Updated: 2021/04/30 19:14:49 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*printf_p_cir(long long num)
{
	char		*tmp;
	long long	num_t;
	int			i;

	i = 11;
	tmp = (char*)malloc(sizeof(char) * 13);
	if (!tmp)
		return (0);
	tmp[12] = '\0';
	while (num != 0)
	{
		num_t = num % 16;
		if (num_t < 10)
			tmp[i--] = num_t + '0';
		else if (num_t < 16 && num_t >= 10)
			tmp[i--] = 'a' + num_t - 10;
		num = num / 16;
	}
	while (i >= 0)
		tmp[i--] = '0';
	return (tmp);
}

int		printf_p_minus(va_list ap, t_ele *ele)
{
	long long	num;
	int			len;
	char		*tmp;

	num = va_arg(ap, long long);
	tmp = printf_p_cir(num);
	len = ft_strlen(tmp);
	if (ele->dot == 2)
	{
		ele->num[1] = ele->num[0];
		ele->num[0] = -1;
	}
	ele->num[0] = ele->num[0] - (ele->num[1] == -1 ? len : ele->num[1]) - 2;
	ele->num[1] = ele->num[1] - len;
	write(1, "0x", 2);
	while (ele->num[1]-- > 0)
		write(1, "0", 1);
	write(1, tmp, len);
	while (ele->num[0]-- > 0)
		write(1, " ", 1);
	return (0);
}

int		printf_p(va_list ap, t_ele *ele)
{
	long long	num;
	char		*tmp;
	int			len;
	int			ch;

	ch = 0;
	if (ele->minus == 1)
		return (printf_p_minus(ap, ele));
	num = va_arg(ap, long long);
	if (num == 0)
		return (write(1, "0x0", 3));
	tmp = printf_p_cir(num);
	len = ft_strlen(tmp);
	ele->num[0] = ele->num[0] - (ele->num[1] == -1 ? len : ele->num[1]) - 2;
	while (ele->zero == 0 && ele->dot < 2 && ele->num[0]-- > 0)
		write(1, " ", 1);
	write(1, "0x", 2);
	ele->num[1] = ele->num[1] - 14;
	if (ele->dot == 2 || ele->zero == 1)
		ch = 1;
	while (ele->num[1]-- > 0 || ((ch == 1) && ele->num[0]-- > 0))
		write(1, "0", 1);
	write(1, tmp, len);
	free(tmp);
	return (0);
}
