#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		num;
	char	**tmp;

	i = 0;
	num = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] != '%')
				num++;
		}
		i++;
	}
	i = 0;
	while (i < num)
	{
		*tmp = va_arg(ap, char*);
        printf("%s", *tmp);
		i++;
	}
	return (0);
}

int	main()
{
	ft_printf("%s %s", "ac", "bc");
}
