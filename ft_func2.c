/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:32:07 by hyejung           #+#    #+#             */
/*   Updated: 2021/05/30 21:14:20 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	nbr_len_minus(int len, t_ele *ele)
{
	if (ele->minus >= 5)
		ele->num[1] = len;
	if (ele->num[1] > len)
		ele->num[0] = ele->num[0] - ele->num[1];
	else
		ele->num[0] = ele->num[0] - len;
	if (ele->form != 'i' && ele->form != 'd')
		ele->num[1] = ele->num[1] - len;
}

void	nbr_len_plus(int num, int len, t_ele *ele)
{
	if (ele->minus == 2)
		ele->num[1] = -1;
	if (ele->minus != 2 && ele->num[1] > len)
		ele->num[0] = ele->num[0] - ele->num[1];
	else
		ele->num[0] = ele->num[0] - len;
	if (ele->form != 'x' && ele->form != 'X')
	{
		if (num < 0 && ele->num[1] >= len)
			ele->num[0]--;
	}
}

int		return_minus(int i, int j, int len, t_ele *ele)
{
	if ((ele->minus >= 5 || i > j) && i > len)
		return (i);
	else if (ele->minus >= 5 || j < len)
		return (len);
	else
		return (j);
}

int		return_plus(int i, int j, int len, t_ele *ele)
{
	if (i > len && (ele->minus == 2 || i > j))
		return (i);
	else if (j < len || ele->minus == 2)
		return (len);
	else
		return (j);
}

void	numleszero(int *len, int *j)
{
	*len = *len + 1;
	*j = *j + 1;
}
