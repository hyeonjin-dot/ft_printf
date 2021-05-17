#include "header.h"

int	printf_pe(va_list ap, t_ele *ele)
{
	int		i;
	char	tmp; 

	tmp = va_arg(ap, int);
	tmp = '%';
	i = ele->num[0];
	if (ele->minus % 2 != 0)
		write(1, &tmp, 1);
	while (ele->dot != 2 && ele->num[0] - 1 > 0)
	{
		if (ele->zero == 1 && ele->minus <= 2)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		ele->num[0]--;
	}
	if (ele->dot == 2 && ele->num[0] != -1)
		write(1, &tmp, 1);
	else if (ele->minus % 2 == 0)
		write(1, &tmp, 1);
	if (ele->dot != 2 && i > 1)
		return (i);
	else
		return (1);
}
