/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:27:01 by hyejung           #+#    #+#             */
/*   Updated: 2021/05/12 22:59:09 by jeonghyeo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	printf_u_cir_minus(t_ele *ele, unsigned int num, unsigned int len, char *tmp)
{
	int			i;

	i = ele->num[0];
	if (ele->dot == 2)
	{
		ele->num[1] = ele->num[0];
		ele->num[0] = -1;
	}
	ele->num[0] = ele->num[0] - (ele->num[1] == -1 ? len : ele->num[1]);
	if (num < 0)
	{
		write(1, "-", 1);
		tmp++;
		len--;
	}
	ele->num[1] = ele->num[1] - len;
	while (ele->num[1]-- > 0)
		write(1, "0", 1);
	write(1, tmp, len);
	while (ele->num[0]-- > 0)
		write(1, " ", 1);
	if (i > (int)len)
		return (i);
	else
		return ((int)len);
}

int	printf_u_cir(t_ele *ele, unsigned int num, unsigned int len, char *tmp)
{
	int			i;

	if (ele->minus == 1)
		return (printf_u_cir_minus(ele, num, len, tmp));
	i = ele->num[0];
	if (ele->dot == 2)
	{
		ele->num[1] = ele->num[0];
		ele->num[0] = -1;
	}
	ele->num[0] = ele->num[0] - (ele->num[1] == -1 ? len : ele->num[1]);
	while (ele->zero == 0 && ele->num[0]-- > 0)
		write(1, " ", 1);
	if (num < 0)
	{
		write(1, "-", 1);
		tmp++;
		len--;
	}
	ele->num[1] = ele->num[1] - len;
	while (ele->num[1]-- > 0 || (ele->zero == 1 && ele->num[0]-- > 0))
		write(1, "0", 1);
	write(1, tmp, len);
	if (i > (int)len)
		return (i);
	else
		return ((int)len);
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
	return (printf_u_cir(ele, num, len, tmp));
}

int	printf_di_minus(va_list ap, t_ele *ele)
{
	int				num;
	int				len;
	int				i;
	char			*tmp;

	num = va_arg(ap, int);
	tmp = ft_itoa(num);
	len = ft_strlen(tmp);
	i = ele->num[0];
	if (ele->num[1] > len)
		ele->num[0] = ele->num[0] - ele->num[1];
	else
		ele->num[0] = ele->num[0] - len;
	if (num < 0)
	{
		write(1, "-", 1);
		tmp++;
		len--;
	}
	if (ele->num[1] > len)
		ele->num[1] = ele->num[1] - len;
	while ((ele->dot == 2 && ele->num[0]-- > 0) || ele->num[1]-- > 0)
		write(1, "0", 1);
	write(1, tmp, len);
	while (ele->dot < 2 && ele->num[0]-- > 0)
		write(1, " ", 1);
	if (num < 0)
		len++;
	if (i > (int)len)
		return (i);
	else if (ele->num[1] < (int)len)
		return ((int)len);
	else
		return (ele->num[1]);
}

int	printf_di(va_list ap, t_ele *ele)
{
	int				num;
	int				len;
	int				i;
	int				j;
	char			*tmp;

	if (ele->minus == 1)
		return (printf_di_minus(ap, ele));
	num = va_arg(ap, int);
	tmp = ft_itoa(num);
	len = ft_strlen(tmp);
	i = ele->num[0];
	j = ele->num[1];
	if (ele->minus == 0 && ele->num[1] > len)
		len = ele->num[1];
	if (ele->minus == 2)
		ele->num[1] = len;
	ele->num[0] = ele->num[0] - len;
	while (ele->zero == 0 && ele->dot < 2 && ele->num[0]-- > 0)
		write(1, " ", 1);
	if (num < 0)
	{
		write(1, "-", 1);
		tmp++;
		len--;
	}
	ele->num[1] = ele->num[1] - ft_strlen(tmp);
	while (ele->num[1]-- > 0)
		write(1, "0", 1);
	while ((ele->dot == 2 || ele->zero == 1) && ele->num[0]-- > 0)
		write(1, "0", 1);
	write(1, tmp, len);
	if (num < 0)
	{
		j++;
		ft_strlcat(tmp, "-", ft_strlen(tmp) + 2);
	}
	if (i > (int)ft_strlen(tmp) && i > j)
		return (i);
	else if (j < (int)ft_strlen(tmp))
		return ((int)ft_strlen(tmp));
	else
		return (j);
}
