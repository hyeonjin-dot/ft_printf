#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char    *printf_x_cir(unsigned int num, char c)
{
    char    *tmp;
    int     num_t;
    int     i;

    i = 7;
	tmp = (char*)malloc(sizeof(9));
	if (!tmp)
		return (0);
	tmp[8] = '\0';
    while (num != 0)
    {
        num_t = num % 16;
		if (num_t < 10)
            tmp[i--] = num_t + '0';
        else
			tmp[i--] = num_t - 10 + ((c == 'x') ? 'a' : 'A');
        num = num / 16;
    }
	while (i >= 0)
		tmp[i--] = 'z';
	i++;
	while (tmp[i] == 'z')
		i++;
	return (tmp + i);
}


int	main()
{
	int*	data;
	char	*tmp;

	tmp = printf_x_cir(123, 'x');
	printf("%s:\n", tmp);
	printf("%i\n", 0123);
}
