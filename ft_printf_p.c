/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:27:14 by hyejung           #+#    #+#             */
/*   Updated: 2021/05/30 22:14:25 by jeonghyeo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	pointer_len(int num, int *len, t_ele *ele)
{
	if (num == 0 && ele->dot == 0)
		*len = 1;
	if (num == 0 && ele->minus == 2)
		*len = 1;
	if (ele->minus == 2)
		ele->num[1] = -1;
	if (ele->minus != 2 && ele->num[1] > *len)
		ele->num[0] = ele->num[0] - ele->num[1] - 2;
	else
		ele->num[0] = ele->num[0] - *len - 2;
	ele->num[1] = ele->num[1] - *len;
}

int		return_pointer(int i, int j, int len, t_ele *ele)
{
	int		t;
	int		k;

	t = 0;
	k = 0;
	if (ele->minus == 2)
		t = 1;
	if (ele->minus >= 5)
		k = 1;
	if ((t == 1 || k == 1 ||i > j + 2) && len + 2 < i)
		return (i);
	else if (t == 1 || k == 1 || j < len)
		return (len + 2);
	else
		return (j + 2);
}

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
		tmp[i--] = 'z';
	i++;
	while (tmp[i] == 'z')
		i++;
	return (tmp + i);
}

int		printf_p_minus(va_list ap, t_ele *ele)
{
	long long	num;
	int			len;
	int			i;
	int			j;
	char		*tmp;

	num = va_arg(ap, long long);
	tmp = printf_p_cir(num);
	len = ft_strlen(tmp);
	if (num == 0)
		tmp = "0";
	if (ele->dot == 2)
		dot_2(ele);
	i = ele->num[0];
	j = ele->num[1];
	pointer_len(num, &len, ele);
	write(1, "0x", 2);
	while (ele->num[1]-- > 0)
		write(1, "0", 1);
	if (num == 0 && ele->dot == 0)
		write(1, "0", 1);
	else
		write(1, tmp, len);
	while (ele->num[0]-- > 0)
		write(1, " ", 1);
	return (return_pointer(i, j, len, ele));
}

int		printf_p(va_list ap, t_ele *ele)
{
	long long	num;
	char		*tmp;
	int			len;
	int			i;
	int			j;

	if (ele->minus % 2 == 1)
		return (printf_p_minus(ap, ele));
	num = va_arg(ap, long long);
	if (ele->dot == 2)
		dot_2(ele);
	i = ele->num[0];
	j = ele->num[1];
	tmp = printf_p_cir(num);
	len = ft_strlen(tmp);
	pointer_len(num, &len, ele);
	while (ele->zero == 0 && ele->dot < 2 && ele->num[0]-- > 0)
		write(1, " ", 1);
	write(1, "0x", 2);
	while (ele->num[1]-- > 0 || (ele->zero == 1 && ele->num[0]-- > 0))
		write(1, "0", 1);
	if (num == 0)
		tmp = "0";
	write(1, tmp, len);
	return (return_pointer(i, j, len, ele));
}
