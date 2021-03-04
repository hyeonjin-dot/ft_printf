

#include "header.h"

void	printf_s(va_list ap)
{
	char	*tmp;
	int		len;
	
	tmp = va_arg(ap, char*);
	len = ft_strlen(tmp);
	write(1, tmp, len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		num;
	char	*tmp;
	char	tt;
	
	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 's')
			{
				printf_s(ap);
			}
			if (str[i + 1] == 'c')
			{
				tt = va_arg(ap, int);
				write(1, &tt, 1);
			}
			if (str[i + 1] == 'd')
			{
				num = va_arg(ap, int);
				tmp = ft_itoa(num);
				write(1, tmp, ft_strlen(tmp));
			}
			if (str[i + 1] == '%')
				write(1, "%", 1);
			i = i + 2;
			continue;
		}
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}

int	main()
{
	ft_printf("%c%s %d", 'h', "world", -22);
}
