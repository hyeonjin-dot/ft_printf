

#include "header.h"

int		star(va_list ap)
{
	int	num;

	num = va_arg(ap, int);
	if (num < 0)
		num = -num;
	return (num);
}

void	printf_s(va_list ap, int wid, int zero) // 07같은 경우 인지하지 못함
{
	char	*tmp;
	int		len;
	
	tmp = va_arg(ap, char*);
	len = ft_strlen(tmp);
	wid = wid - len;
	while (wid > 0)
	{
		if (zero == 0)
			write(1, " ", 1);
		else
			write(1, "0", 1);
		wid--;
	}
	write(1, tmp, len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		num;
	int		wid;
	int		zero;
	char	*tmp;
	char	tt;
	
	i = 0;
	zero = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i] == '%')
				i++;
			if (str[i - 1] == '%' && str[i] == '%')
				 write(1, "%", 1);
			if (str[i] == '*')
				num = star(ap);
			if (str[i] >= '0' && str[i] <= '9')
			{
				if (str[i] == '0')
					zero++;
				wid = ft_atoi(&str[i]);
				while (str[i] >= '0' && str[i] <= '9')
					i++;
			}
			if (str[i] == 's')
			{
				printf_s(ap, wid, zero);
			}
			if (str[i] == 'c')
			{
				tt = va_arg(ap, int);
				write(1, &tt, 1);
			}
			if (str[i] == 'd' || str[i] == 'i')
			{
				num = va_arg(ap, int);
				tmp = ft_itoa(num);
				write(1, tmp, ft_strlen(tmp));
			}
			if (str[i] == 'p') // 수정 필요
			{
				tmp = va_arg(ap, char*);
				write(1, &tmp, ft_strlen(tmp));
			}
			if (str[i] == 'x' || str[i] == 'X')
			{

			}
			if (str[i] == 'u')
			{
				num = va_arg(ap, long long);
				if (num < 0)
					num = 4294967295 + num + 1;
				tmp = ft_itoa(num / 1000000000);
				if (tmp != 0)
					write(1, &tmp, ft_strlen(tmp));
				tmp = ft_itoa(num % 1000000000);
				write(1, &tmp, ft_strlen(tmp));
			}
			//x(16 little) X(16 big)
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

	ft_printf("s:%011s:", "world");
}
