/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:27:46 by hyejung           #+#    #+#             */
/*   Updated: 2021/05/30 21:17:17 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int		check_num(unsigned int num)
{
	if (num < 0)
		num = 4294967295 + num + 1;
	return (num);
}

char				*printf_x_cir(unsigned int num, char c)
{
	char			*str;
	int				num_t;
	int				i;

	i = 7;
	if (num == 0)
		return ("0");
	if (!(str = (char*)malloc(sizeof(9))))
		return (0);
	str[8] = '\0';
	while (num != 0)
	{
		num_t = num % 16;
		if (num_t < 10)
			str[i--] = num_t + '0';
		else
			str[i--] = num_t - 10 + ((c == 'x') ? 'a' : 'A');
		num = num / 16;
	}
	while (i >= 0)
		str[i--] = 'z';
	i++;
	while (str[i] == 'z')
		i++;
	return (str + i);
}

int					printf_x_minus(va_list ap, t_ele *ele)
{
	unsigned int	num;
	int				len;
	int				i;
	int				j;
	char			*tmp;

	num = va_arg(ap, int);
	num = check_num(num);
	tmp = ft_strdup(printf_x_cir(num, ele->form));
	len = ft_strlen(tmp);
	if (ele->dot == 2)
		dot_2(ele);
	i = ele->num[0];
	j = ele->num[1];
	if (num == 0 && ele->dot >= 1 && ele->num[1] <= 0)
		return (numiszero(i, ele));
	nbr_len_minus(len, ele);
	while (ele->num[1]-- > 0)
		write(1, "0", 1);
	write(1, tmp, len);
	while (ele->num[0]-- > 0)
		write(1, " ", 1);
	if (num != 0)
		free(tmp);
	return (return_minus(i, j, len, ele));
}

void				x_write(int len, t_ele *ele)
{
	int				i;

	i = 0;
	if (ele->zero == 1 && ele->dot == 1)
		i = 1;
	while (ele->zero == 0 && ele->num[0]-- > 0)
		write(1, " ", 1);
	while (i == 1 && ele->minus != 2 && ele->num[0]-- > 0)
		write(1, " ", 1);
	ele->num[1] = ele->num[1] - len;
	while (ele->num[1]-- > 0 || (ele->zero == 1 && ele->num[0]-- > 0))
		write(1, "0", 1);
}

int					printf_x(va_list ap, t_ele *ele)
{
	unsigned int	num;
	int				len;
	int				i;
	int				j;
	char			*tmp;

	if (ele->minus % 2 == 1)
		return (printf_x_minus(ap, ele));
	num = va_arg(ap, int);
	num = check_num(num);
	tmp = ft_strdup(printf_x_cir(num, ele->form));
	len = ft_strlen(tmp);
	if (ele->dot == 2)
		dot_2(ele);
	i = ele->num[0];
	j = ele->num[1];
	if (num == 0 && ele->dot != 0 && ele->num[1] < 1)
		return (numiszero(i, ele));
	nbr_len_plus(num, len, ele);
	x_write(len, ele);
	write(1, tmp, len);
	if (num != 0)
		free(tmp);
	return (return_plus(i, j, len, ele));
}
