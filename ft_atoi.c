#include "header.h"

int	checkspace(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	num;
	int	count;

	i = 0;
	num = 0;
	count = 0;
	while ((str[i] != '\0') && (checkspace((char)str[i]) == 1))
		i++;
	minus = ((char)str[i] == '-') ? -1 : 1;
	if ((char)str[i] == '+' || minus == -1)
		i++;
	while ((char)str[i] >= '0' && (char)str[i] <= '9' && str[i])
	{
		num = (num * 10) + ((char)str[i++] - '0');
		count++;
	}
	if (count >= 20)
		return ((minus == 1) ? -1 : 0);
	else
		return (minus * num);
}
