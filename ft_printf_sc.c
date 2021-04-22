
#include "header.h"

int		printf_s(va_list ap, t_ele ele)
{
    char    *tmp;
    int     len;

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
	return (0);
}

int    printf_c(va_list ap, t_ele ele)
{
    char    tmp;

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
	return (0);
}
