/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:30:47 by hyejung           #+#    #+#             */
/*   Updated: 2021/05/29 18:30:51 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	printf_pe(t_ele *ele)
{
	int		i;

	i = ele->num[0];
	if (ele->minus % 2 != 0)
		write(1, "%", 1);
	while (ele->dot != 2 && ele->num[0] - 1 > 0)
	{
		if (ele->zero == 1 && ele->minus % 2 != 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		ele->num[0]--;
	}
	if (ele->dot == 2 && ele->num[0] != -1)
		write(1, "%", 1);
	else if (ele->minus % 2 == 0)
		write(1, "%", 1);
	if (ele->dot != 2 && i > 1)
		return (i);
	else
		return (1);
}
