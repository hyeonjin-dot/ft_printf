

typedef	struct  elements
{
    int minus;
    int num[2];
    int st;
    int dot;
	int	zero;
}	new_elements;

void	reset_elements(new_elements ele)
{
	ele.minus = 0;
	ele.num[0] = -1;
	ele.num[1] = -1;
	ele.st = 0;
	ele.dot = 0;
	ele.zero = 0;
}

int	ft_printf(const char *str,...)
{
	va_list	ap;
	struct	new_elements ele;
	int		i;
	int		j;

	i = 0;
	j = 0;
	reset_elements(&ele);
	va_start(ap, str);
	while (str[i])
	{
		if (str[i++] == '%')
		{
			if (str[i] == '%')
				write(1, "%", 1);
			if (str[i] >= '0' && str[i] <= '9')
			{
				if (str[i] == '0')
					ele.zero++;
				ele.num[j++] = ft_atoi(&str[i]);
				while (str[i] >= '0' && str[i] <= '9')
					i++;
			}
			if (str[i] == '.')
				ele.zero = 1;
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

