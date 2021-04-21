

#include "header.h"

t_ele	reset_elements(t_ele ele)
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

void	p_ft_bzero(void	*s, size_t n, char a)
{
	int	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = a;
		i++;
	}
	*(char *)(s + i) = '\0';
}

void	printf_s(va_list ap, t_ele ele)
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
		while (ele.num[0]-- > 0)
		{
			if (ele.zero == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
		write(1, tmp, len);
	}
}

char	*printf_p_cir(long long num) // 12자리 16진수 만듥리
{
	char	*tmp;
	char	*str;
	long long	num_t;
	int	i;
	int	j;

	i = 0;
	j = 0;
	tmp = (char*)malloc(sizeof(char) * 13);
	if (!tmp)
		return (0);
	while (num != 0)
	{
		num_t = num % 16;
		if (num_t < 10)
			tmp[i++] = num_t + '0';
		else if (num_t < 16 && num_t >= 10)
			tmp[i++] = 'a' + num_t - 10;
		num = num / 16;
	}
	tmp[i--] = '\0';
	str = (char*)malloc(sizeof(13));
	if (!str)
		return (0);
	while (i >= 0)
		str[j++] = tmp[i--];
	str[j] = '\0';
	if (j < 12)
	{
		free(tmp);
		p_ft_bzero(tmp, 12 - j, '0');
		ft_strlcat(tmp, str, 13);
		return (tmp);
	}
	return (str);
}

int		printf_p_minus(va_list ap, t_ele ele)
{
	long long	num;
    int     len;
    char            *tmp;

    num = va_arg(ap, long long);
    tmp = printf_p_cir(num);
    len = ft_strlen(tmp);
    if (ele.dot == 2)
    {
        ele.num[1] = ele.num[0];
        ele.num[0] = -1;
    }
    ele.num[0] = ele.num[0] - (ele.num[1] == -1 ? len : ele.num[1]) - 2;
    ele.num[1] = ele.num[1] - len;
	write(1, "0x", 2);
    while (ele.num[1]-- > 0)
        write(1, "0", 1);
    write(1, tmp, len);
    while (ele.num[0]-- > 0)
        write(1, " ", 1);
    return (0);
}

int		printf_p(va_list ap, t_ele ele) // - m.n 0x 출력해주기
{
	long long	num;
	char		*tmp;
	int			len;

	if (ele.minus == 1)
		return (printf_p_minus(ap, ele));
	num = va_arg(ap, long long);
	if (num == 0)
		return (write(1, "0x0", 3));
	tmp = printf_p_cir(num);
	len = ft_strlen(tmp);
	if (ele.dot == 2)
	{
		ele.num[1] = ele.num[0];
		ele.num[0] = -1;
	}
	ele.num[0] = ele.num[0] - (ele.num[1] == -1 ? len : ele.num[1]) - 2;
	while (ele.zero == 0 && ele.num[0]-- > 0)
		write(1, " ", 1);
	write(1, "0x", 2);
	ele.num[1] = ele.num[1] - 14;
	while (ele.num[1]-- > 0 || (ele.zero == 1 && ele.num[0]-- > 0))
		write(1, "0", 1);
	write(1, tmp, len);
	free(tmp);
	return (0);
}


void	printf_c(va_list ap, t_ele ele)
{
	char	tmp;

	tmp = va_arg(ap, int);
	if (ele.dot == 2)
		write(1, &tmp, 1);
	if (ele.minus == 1)
		write(1, &tmp, 1);
	while (ele.num[0] - 1 > 0)
	{
		if (ele.zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		ele.num[0]--;
	}
	if (ele.minus == 0)
		write(1, &tmp, 1);

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

// main 함수 
int	main()
{
	int	*poi;
	int	num;

	num = 5;
	poi = &num;
	printf("%p:\n", NULL);
	ft_printf("%p:\n", poi);
	ft_printf("%-5.3d:\n", 32);
}
