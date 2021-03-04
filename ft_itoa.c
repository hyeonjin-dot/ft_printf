#include "header.h"

int		check_itoa(int num)
{
	int		i;

	i = 1;
	if (num == -2147483647 - 1)
		return (11);
	if (num < 0)
	{
		i++;
		num = -num;
	}
	while (num >= 10)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*new;

	i = check_itoa(n);
	if (!(new = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	new[i--] = '\0';
	if (n == -2147483647 - 1)
	{
		new[i] = '8';
		n = -214748364;
		i--;
	}
	if (n < 0)
	{
		new[0] = '-';
		n = -n;
	}
	while (n >= 10)
	{
		new[i--] = (n % 10) + '0';
		n = n / 10;
	}
	new[i] = n + '0';
	return (new);
}
