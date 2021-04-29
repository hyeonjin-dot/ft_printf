
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

void	star(va_list ap, t_ele *ele)
{
	int	num;

	num = va_arg(ap, int);
	if (num < 0)
		num = -num;
	if (ele->num[0] == -1)
		ele->num[0] = num;
	else
		ele->num[1] = num;
}

void	printf_form(va_list ap, t_ele *ele)
{
	if (ele->form == 's')
		printf_s(ap, *ele);
	if (ele->form == 'd' || ele->form == 'i')
		printf_di(ap, *ele);
	if (ele->form == 'c')
		printf_c(ap, *ele);
	if (ele->form == 'u')
		printf_u(ap, *ele);
	if (ele->form == 'x' || ele->form == 'X')
		printf_x(ap, *ele);
	if (ele->form == 'p')
		printf_p(ap, *ele);
}

int		ft_check(char *str, int i, t_ele *ele, va_list ap)
{
	while (check_form(str[i]) == 0 && str[i] != '%')
	{
		if (str[i] == '*')
			star(ap, ele);
		else if (str[i] == '-')
			ele->minus = 1;
		else if (str[i] >= '0' && str[i] <= '9')
		{
			if (str[i] == '0')
				ele->zero++;
			if (ele->num[0] == -1)
				(ele->num[0] = ft_atoi(&str[i]));
			else
				(ele->num[1] = ft_atoi(&str[i]));
			while (str[i] >= '0' && str[i] <= '9')
				i++;
			i--;
		}
		else if (str[i] == '.')
			ele->dot = (ele->num[0] == -1 ? 2 : 1);
		i++;
	}
	ele->form = str[i];
	printf_form(ap, ele);
	return (i);
}

int		ft_printf(const char *str, ...)
{
	va_list ap;
	t_ele	ele;
	int     i;

	i = 0;
	ele = reset_elements();
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
			{
				write(1, "%", 1);
				continue ;
			}
			i = ft_check((char*)str, i, &ele, ap);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	return (0);
}

/*main 함수 */
int	main()
{
	int	*poi;
	int	num;

	num = 5;
	poi = &num;
	printf("%p:\n", poi);
	ft_printf("%p:aa\n", poi);
	ft_printf("%s:\n", NULL);
	ft_printf("%-5d33:\n", 32);
}
