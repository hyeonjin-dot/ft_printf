#include "header.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		num;
	int		len;
	char	*tmp;
	
	i = 0;
	num = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] != '%')
				num++;
		}
		i++;
	}
	i = 0;
	while (i < num)
	{
		tmp = va_arg(ap, char*);
		len = ft_strlen(tmp);
		write(1, (tmp), len);
		i++;
	}
	return (0);
}

int	main()
{
	printf("%2s\n","hello");
	ft_printf("%s %s", "AS", "cd");
}
