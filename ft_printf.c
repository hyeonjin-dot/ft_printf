

#include "header.h"

t_ele	reset_elements(void)
{
	t_ele	ele;

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

t_ele	star(va_list ap, t_ele ele)
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

void	printf_form(va_list ap, t_ele ele)
{
	if (ele.form == 's')
		printf_s(ap, ele);
	if (ele.form == 'd' || ele.form == 'i')
		printf_di(ap, ele);
	if (ele.form == 'c')
		printf_c(ap, ele);
	if (ele.form == 'u')
		printf_u(ap, ele);
	if (ele.form == 'x' || ele.form == 'X')
		printf_x(ap, ele);
	if (ele.form == 'p')
		printf_p(ap, ele);
}

int	ft_printf(const char *str, ...)
{
	va_list ap;
	t_ele	ele;
	int     i;
	int     j;

	i = 0;
	j = 0;
	ele = reset_elements();
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

/*main 함수 
int	main()
{
	int	*poi;
	int	num;

	num = 5;
	poi = &num;
	printf("%s:\n", NULL);
	ft_printf("%paa:\n", poi);
	ft_printf("%-5.3d33:\n", 32);
}*/
