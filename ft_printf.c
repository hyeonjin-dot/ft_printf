

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
	if (ele.dot != 0)
	{
		if (ele.num[1] == -1)
		{
			ele.num[1] = ele.num[0];
			ele.num[0] = -1;
		}
		len = (len > ele.num[1]) ? ele.num[1] : len;
	}
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

int		printf_di_minus(va_list ap, new_elements ele)
{
	int		num;
	int		len;
	char	*tmp;

	num = va_arg(ap, int);
	tmp = ft_itoa(num);
	len = ft_strlen(tmp);
	if (ele.dot == 2)
	{
		ele.num[1] = ele.num[0];
		ele.num[0] = -1;
	}
	ele.num[0] = ele.num[0] - (ele.num[1] == -1 ? len : ele.num[1]);
	if (num < 0)
	{
		write(1, "-", 1);
		tmp++;
		len--;
	}
	ele.num[1] = ele.num[1] - len;
	while (ele.num[1]-- > 0)
		write(1, "0", 1);
	write(1, tmp, len);
	while (ele.num[0]-- > 0)
		write(1, " ", 1);
	return (0);
}

int		printf_di(va_list ap, new_elements ele)
{
	int		num;
	int		len;
	char	*tmp;

	if (ele.minus == 1)
		return (printf_di_minus(ap, ele));
	num = va_arg(ap, int);
	tmp = ft_itoa(num);
	len = ft_strlen(tmp);
	if (ele.dot == 2)
	{
		ele.num[1] = ele.num[0];
		ele.num[0] = -1;
	}
	ele.num[0] = ele.num[0] - (ele.num[1] == -1 ? len : ele.num[1]);
	while (ele.num[0]-- > 0)
		write(1, " ", 1);
	if (num < 0)
	{
		write(1, "-", 1);
		tmp++;
		len--;
	}
	ele.num[1] = ele.num[1] - len;
	while (ele.num[1]-- > 0)
		write(1, "0", 1);
	write(1, tmp, len);
	return (0);
}

void	printf_c(va_list ap, new_elements ele)
{
	//화이팅~~
}

void	printf_form(va_list ap, new_elements ele)
{
	if (ele.form == 's')
		printf_s(ap, ele);
	if (ele.form == 'd' || ele.form == 'i')
		printf_di(ap, ele);
	//if (ele.form == 'c')
		//printf_c(ap, ele);

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
				else if (str[i] == '-')
					ele.minus = 1;
				else if (str[i] >= '0' && str[i] <= '9')
				{
					if (str[i] == '0')
						ele.zero++;
					ele.num[j] == -1 ? j : j++;
					ele.num[j] = ft_atoi(&str[i]);
					j == 0 ? j++ : j ;
					while (str[i] >= '0' && str[i] <= '9')
						i++;
					i--;
				}
				else if (str[i] == '.')
					ele.dot = (ele.num[0] == -1 ? 2: 1);
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
	ft_printf("%.4d", -2);
}

