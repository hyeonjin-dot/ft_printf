/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 20:53:16 by hyejung           #+#    #+#             */
/*   Updated: 2021/05/30 21:13:50 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	minus_write(int num, char *tmp, int *len, t_ele *ele)
{
	if (num < 0)
	{
		write(1, "-", 1);
		tmp++;
		*len = *len - 1;
		if (ele->minus >= 5)
			ele->num[1]--;
	}
	if (num < 0 && ele->num[1] > *len)
		ele->num[0]--;
	ele->num[1] = ele->num[1] - *len;
	while (ele->num[1]-- > 0)
		write(1, "0", 1);
	write(1, tmp, *len);
	while (ele->num[0]-- > 0)
		write(1, " ", 1);
}

int		printf_di_minus(va_list ap, t_ele *ele)
{
	int		num;
	int		len;
	int		i;
	int		j;
	char	*tmp;

	num = va_arg(ap, int);
	tmp = ft_itoa(num);
	len = ft_strlen(tmp);
	if (ele->dot == 2)
		dot_2(ele);
	i = ele->num[0];
	j = ele->num[1];
	if (num == 0 && ele->dot >= 1 && ele->num[1] <= 0)
		return (numiszero(i, ele));
	nbr_len_minus(len, ele);
	minus_write(num, tmp, &len, ele);
	if (num < 0)
		numleszero(&len, &j);
	return (return_minus(i, j, len, ele));
}

void	id_plus(t_ele *ele)
{
	int		i;

	i = 0;
	while (ele->zero == 0 && ele->num[0]-- > 0)
		write(1, " ", 1);
	if (ele->zero == 1 && ele->dot == 1)
		i = 1;
	while (i == 1 && ele->minus != 2 && ele->num[0]-- > 0)
		write(1, " ", 1);
}

char	*id_bf_write(int num, t_ele *ele)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	tmp = ft_itoa(num);
	len = ft_strlen(tmp);
	if (num < 0)
	{
		write(1, "-", 1);
		tmp++;
		len--;
	}
	ele->num[1] = ele->num[1] - len;
	while (ele->num[1]-- > 0)
		write(1, "0", 1);
	if (ele->dot == 0 && ele->zero == 1)
		i = 1;
	while (i == 1 && ele->num[0]-- > 0)
		write(1, "0", 1);
	if (ele->zero == 1 && ele->minus == 2)
		i = 2;
	while (i == 2 && ele->num[0]-- > 0)
		write(1, "0", 1);
	return (tmp);
}

int		printf_di(va_list ap, t_ele *ele)
{
	int		num;
	int		len;
	int		i;
	int		j;
	char	*tmp;

	if (ele->minus % 2 == 1)
		return (printf_di_minus(ap, ele));
	num = va_arg(ap, int);
	tmp = ft_itoa(num);
	len = ft_strlen(tmp);
	if (ele->dot == 2)
		dot_2(ele);
	i = ele->num[0];
	j = ele->num[1];
	if (num == 0 && ele->dot != 0 && ele->num[1] < 1)
		return (numiszero(i, ele));
	nbr_len_plus(num, len, ele);
	id_plus(ele);
	tmp = id_bf_write(num, ele);
	len = ft_strlen(tmp);
	write(1, tmp, len);
	if (num < 0)
		numleszero(&len, &j);
	return (return_plus(i, j, len, ele));
}
