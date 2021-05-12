/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:27:46 by hyejung           #+#    #+#             */
/*   Updated: 2021/05/08 16:25:38 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*printf_x_cir(unsigned int num, char c)
{
	char	*tmp;
	int		num_t;
	int		i;

	i = 7;
	tmp = (char*)malloc(sizeof(9));
	if (!tmp)
		return (0);
	tmp[8] = '\0';
	while (num != 0)
	{
		num_t = num % 16;
		if (num_t < 10)
			tmp[i--] = num_t + '0';
		else
			tmp[i--] = num_t - 10 + ((c == 'x') ? 'a' : 'A');
		num = num / 16;
	}
	while (i >= 0)
		tmp[i--] = 'z';
	i++;
	while (tmp[i] == 'z')
		i++;
	return (tmp + i);
}

int		printf_x_minus(va_list ap, t_ele *ele)
{
	unsigned int	num;
	int				len;
	int				i;
	char			*tmp;

	num = va_arg(ap, int);
	if (num < 0)
		num = 4294967295 + num + 1;
	tmp = printf_x_cir(num, ele->form);
	len = ft_strlen(tmp);
	i = ele->num[0];
	if (ele->dot == 2)
	{
		ele->num[1] = ele->num[0];
		ele->num[0] = -1;
	}
	ele->num[0] = ele->num[0] - (ele->num[1] == -1 ? len : ele->num[1]);
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

int		printf_x(va_list ap, t_ele *ele)
{
	unsigned int	num;
	int				len;
	int				i;
	char			*tmp;

	if (ele->minus == 1)
		return (printf_x_minus(ap, ele));
	num = va_arg(ap, int);
	if (num < 0)
		num = 4294967295 + num + 1;
	tmp = printf_x_cir(num, ele->form);
	len = ft_strlen(tmp);
	i = ele->num[0];
	if (ele->dot == 2)
	{
		ele->num[1] = ele->num[0];
		ele->num[0] = -1;
	}
	ele->num[0] = ele->num[0] - (ele->num[1] == -1 ? len : ele->num[1]);
	while (ele->zero == 0 && ele->num[0]-- > 0)
		write(1, " ", 1);
	ele->num[1] = ele->num[1] - len;
	while (ele->num[1]-- > 0 || (ele->zero == 1 && ele->num[0]-- > 0))
		write(1, "0", 1);
	write(1, tmp, len);
	free(tmp);
	if (i > (int)len)
		return (i);
	else
		return ((int)len);
}