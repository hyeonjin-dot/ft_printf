/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:26:33 by hyejung           #+#    #+#             */
/*   Updated: 2021/05/28 19:48:18 by jeonghyeo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_form(char c)
{
	if (c == 'c' || c == 's' || c == 'd')
		return (1);
	else if (c == 'i' || c == 'x' || c == 'X')
		return (1);
	else if (c == 'u' || c == 'p')
		return (1);
	else
		return (0);
}

void dot_2(t_ele *ele)
{
	ele->num[1] = ele->num[0];
	ele->num[0] = -1;
}

int	numiszero(int i, t_ele *ele)
{
	while (ele->num[0]-- > 0)
		write(1, " ", 1);
	if (i != -1)
		return (i);
	else
		return (0);
}

