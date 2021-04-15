

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

char	*printf_x_cir(unsigned int num, char c)
{
	char    *tmp;
	char    *str;
	int     num_t;
	int     i;
	int     j;

	i = 0;
	tmp = (char*)malloc(sizeof(9));
	while (num != 0)
	{
		num_t = num % 16;
		if (num_t < 10)
			tmp[i++] = num_t + '0';
		else
		{
			j = ((c == 'x') ? 'a' : 'A');
			tmp[i++] = j + num_t - 10;
		}
		num = num / 16;
	}
	tmp[i--] = '\0';
	str = (char*)malloc(sizeof(i + 1));
	if (!str)
		return (0);
	j = 0;
	while (i >= 0)
		str[j++] = tmp[i--];
	str[j] = '\0';
	return (str);
}
int		printf_x_minus(va_list ap, t_ele ele)
{
	unsigned int     num;
    int     len;
    char    		*tmp;

    num = va_arg(ap, int);
	if (num < 0)
		num = 4294967295 + num + 1;
    tmp = printf_x_cir(num, ele.form);
    len = ft_strlen(tmp);
    if (ele.dot == 2)
    {
        ele.num[1] = ele.num[0];
        ele.num[0] = -1;
    }
    ele.num[0] = ele.num[0] - (ele.num[1] == -1 ? len : ele.num[1]);
	ele.num[1] = ele.num[1] - len;
    while (ele.num[1]-- > 0)
        write(1, "0", 1);
    write(1, tmp, len);
    while (ele.num[0]-- > 0)
        write(1, " ", 1);
    return (0);
}

int		printf_x(va_list ap, t_ele ele)
{
	unsigned int	num;
	int     len;
	char    *tmp;

	if (ele.minus == 1)
		return (printf_x_minus(ap, ele));
	num = va_arg(ap, int);
	if (num < 0)
		num = 4294967295 + num + 1;
	tmp = printf_x_cir(num, ele.form);
	len = ft_strlen(tmp);
	if (ele.dot == 2)
	{
		ele.num[1] = ele.num[0];
		ele.num[0] = -1;
	}
	ele.num[0] = ele.num[0] - (ele.num[1] == -1 ? len : ele.num[1]);
	while (ele.zero == 0 && ele.num[0]-- > 0)
		write(1, " ", 1);
	ele.num[1] = ele.num[1] - len;
	while (ele.num[1]-- > 0 || (ele.zero == 1 && ele.num[0]-- > 0))
		write(1, "0", 1);
	write(1, tmp, len);
	free(tmp);
	return (0);
}

int		printf_u_cir_minus(t_ele ele, unsigned int num, unsigned int len, char *tmp)
{
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

int		printf_u_cir(t_ele ele, unsigned int num, unsigned int len, char *tmp)
{
	if (ele.minus == 1)
		return (printf_u_cir_minus(ele, num, len, tmp));
	if (ele.dot == 2)
	{
		ele.num[1] = ele.num[0];
		ele.num[0] = -1;
	}
	ele.num[0] = ele.num[0] - (ele.num[1] == -1 ? len : ele.num[1]);
	while (ele.zero == 0 && ele.num[0]-- > 0)
		write(1, " ", 1);
	if (num < 0)
	{
		write(1, "-", 1);
		tmp++;
		len--;
	}
	ele.num[1] = ele.num[1] - len;
	while (ele.num[1]-- > 0 || (ele.zero == 1 && ele.num[0]-- > 0))
		write(1, "0", 1);
	write(1, tmp, len);
	return (0);
}

int		printf_u(va_list ap, t_ele ele)
{
	unsigned int	num;
	unsigned int	num_1;
	unsigned int	len;
	char			*tmp;
	char			*tmp_1;

	num = va_arg(ap, int);
	if (num > 2147483647)
	{
		len = 10;
		num_1 = num / 1000;
		num = num % 1000;
		tmp = ft_itoa((int)num_1);
		tmp_1 = ft_itoa((int)num);
		tmp = ft_strjoin(tmp, tmp_1);
	}
	else
	{
		tmp = ft_itoa((int)num);
		len = ft_strlen(tmp);
	}
	printf_u_cir(ele, num, len, tmp);
	return(0);
}

int		printf_di_minus(va_list ap, t_ele ele) // -플래그가 존재하는 경우
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

int		printf_di(va_list ap, t_ele ele)
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
	while (ele.zero == 0 && ele.num[0]-- > 0)
		write(1, " ", 1);
	if (num < 0)
	{
		write(1, "-", 1);
		tmp++;
		len--;
	}
	ele.num[1] = ele.num[1] - len;
	while (ele.num[1]-- > 0 || (ele.zero == 1 && ele.num[0]-- > 0))
		write(1, "0", 1);
	write(1, tmp, len);
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

int	main()
{
	int	*poi;
	int	num;

	num = 5;
	poi = &num;
	printf("%020p:\n", poi);
	ft_printf("%020p:\n", poi);
}
