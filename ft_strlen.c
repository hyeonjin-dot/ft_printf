#include "header.h"

int	ft_strlen(const char *str)
{
	int i;

	i = 0;
		while (*str != '\0')
		{
			i++;
			str++;
		}
	return (i);
}
