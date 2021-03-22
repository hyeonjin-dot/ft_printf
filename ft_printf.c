

#include "header.h"

new_elements	reset_elements(new_elements ele)
{
	ele.minus = 0;
    ele.num[0] = -1;
    ele.num[1] = -1;
    ele.dot = 0;
    ele.zero = 0;
	ele.form = 'q';
	return (ele);
}

int		check_form(char c)
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

new_elements	star(va_list ap, new_elements ele)
{
	int	num;

	num = va_arg(ap, int);
	if (num < 0)
		num = -num;
	if (ele.num[0] == -1)
		ele.num[0] = num;
	else
		ele.num[1] = num;
	return (ele);
}

void	printf_s(va_list ap, new_elements ele)
{
	char	*tmp;
	int		len;

	tmp = va_arg(ap, char*);
	len = ft_strlen(tmp);
	ele.num[0] = ele.num[0] - len;
	if (ele.minus == 1)
	{
		write(1, tmp, len);
		while ((ele.num[0])-- > 0)
			 write(1, " ", 1);
	}
	else
	{
		while (ele.num[0] > 0)
		{
			if (ele.zero == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			(ele.num[0])--;
		}
		write(1, tmp, len);
	}
}

void	printf_form(va_list ap, new_elements ele)
{
	if (ele.form == 's')
		printf_s(ap, ele);
}

int	ft_printf(const char *str, ...)
{
	va_list ap;
	new_elements	ele;
	int     i;
	int     j;

	i = 0;
	j = 0;
	ele = reset_elements(ele);
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while (check_form(str[i]) == 0 && str[i] != '%')
			{
				if (str[i] == '*')
					ele = star(ap, ele);
				if (str[i] == '-')
					ele.minus = 1;
				if (str[i] >= '0' && str[i] <= '9')
				{
					if (str[i] == '0')
						ele.zero++;
					ele.num[j++] = ft_atoi(&str[i]);
					while (str[i] >= '0' && str[i] <= '9')
						i++;
					i--;
				}
				if (str[i] == '.')
					ele.dot = 1;
				i++;
			}
			if (str[i] == '%')
			{
				write(1, "%", 1);
				continue ;
			}
			ele.form = str[i];
			printf_form(ap, ele);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	return (0);
}

int	main()
{
	int num;
	int *tmp;

	num = 10;
	tmp = &num;

	ft_printf("%*s",7, "world");
}
