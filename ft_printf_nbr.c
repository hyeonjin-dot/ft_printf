/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:27:01 by hyejung           #+#    #+#             */
/*   Updated: 2021/05/30 21:16:37 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	printf_u_cir_minus(t_ele *ele, unsigned int num, int len, char *tmp)
{
	int			i;
	int			j;

	if (ele->dot == 2)
		dot_2(ele);
	i = ele->num[0];
	j = ele->num[1];
	if (num == 0 && ele->dot >= 1 && ele->num[1] <= 0)
		return (numiszero(i, ele));
	if (ele->minus >= 5)
		ele->num[1] = len;
	if (ele->minus < 5 && ele->num[1] > (int)len)
		ele->num[0] = ele->num[0] - ele->num[1];
	else
		ele->num[0] = ele->num[0] - len;
	ele->num[1] = ele->num[1] - len;
	while (ele->num[1]-- > 0)
		write(1, "0", 1);
	write(1, tmp, len);
	while (ele->num[0]-- > 0)
		write(1, " ", 1);
	return (return_minus(i, j, len, ele));
}

int	printf_u_cir(t_ele *ele, unsigned int num, int len, char *tmp)
{
	int			i;
	int			j;
	int			k;

	k = 0;
	if (ele->minus % 2 == 1)
		return (printf_u_cir_minus(ele, num, len, tmp));
	if (ele->dot == 2)
		dot_2(ele);
	i = ele->num[0];
	j = ele->num[1];
	if (num == 0 && ele->dot > 0 && ele->num[1] < 1)
		return (numiszero(i, ele));
	nbr_len_plus(num, len, ele);
	while (ele->zero == 0 && ele->num[0]-- > 0)
		write(1, " ", 1);
	if (ele->zero == 1 && ele->dot == 1 && ele->minus != 2)
		k = 1;
	while (k == 1 && ele->num[0]-- > 0)
		write(1, " ", 1);
	ele->num[1] = ele->num[1] - len;
	while (ele->num[1]-- > 0 || (ele->zero == 1 && ele->num[0]-- > 0))
		write(1, "0", 1);
	write(1, tmp, len);
	return (return_plus(i, j, len, ele));
}

int	printf_u(va_list ap, t_ele *ele)
{
	unsigned int	num;
	unsigned int	num_1;
	unsigned int	len;
	char			*tmp;
	char			*tmp_1;

	num = va_arg(ap, int);
	if (num > 2147483647)
	{
		len = 10;
		num_1 = num / 1000;
		num = num % 1000;
		tmp = ft_itoa((int)num_1);
		tmp_1 = ft_itoa((int)num);
		tmp = ft_strjoin(tmp, tmp_1);
	}
	else
	{
		tmp = ft_itoa((int)num);
		len = ft_strlen(tmp);
	}
	return (printf_u_cir(ele, num, (int)len, tmp));
}
