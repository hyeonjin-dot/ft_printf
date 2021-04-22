
#include "header.h"

int     printf_u_cir_minus(t_ele ele, unsigned int num, unsigned int len, char *tmp)
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

int     printf_u_cir(t_ele ele, unsigned int num, unsigned int len, char *tmp)
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

int     printf_u(va_list ap, t_ele ele)
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

int     printf_di_minus(va_list ap, t_ele ele)
{
	int				num;
	int				len;
	char			*tmp;

	num = va_arg(ap, int);
	tmp = ft_itoa(num);
    len = ft_strlen(tmp);
    ele.num[0] = ele.num[0] - (ele.num[1] == -1 ? len : ele.num[1]);
    if (num < 0)
    {
        write(1, "-", 1);
        tmp++;
        len--;
    }
    ele.num[1] = ele.num[1] - len;
    while ((ele.dot == 2 && ele.num[0]-- > 0) || ele.num[1]-- > 0)
        write(1, "0", 1);
    write(1, tmp, len);
    while (ele.dot < 2 && ele.num[0]-- > 0)
        write(1, " ", 1);
    return (0);
}

int     printf_di(va_list ap, t_ele ele)
{
	int				num;
	int				len;
	char			*tmp;

	if (ele.minus == 1)
		return (printf_di_minus(ap, ele));
	num = va_arg(ap, int);
	tmp = ft_itoa(num);
	len = ft_strlen(tmp);
	ele.num[0] = ele.num[0] - (ele.num[1] == -1 ? len : ele.num[1]);
	while (ele.zero == 0 && ele.dot < 2 && ele.num[0]-- > 0)
		write(1, " ", 1);
	if (num < 0)
	{
		write(1, "-", 1);
		tmp++;
		len--;
	}
	ele.num[1] = ele.num[1] - len;
	while (ele.num[1]-- > 0 || ((ele.dot == 2 || ele.zero == 1) && ele.num[0]-- > 0))
		write(1, "0", 1);
	write(1, tmp, len);
	return (0);
}
