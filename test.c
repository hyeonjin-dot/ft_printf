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

 char    *printf_p_cir(long long num) // 12자리 16진수 만듥리
 {
     char		*tmp;
     long long	num_t;
     int		i;

     i = 11;
     tmp = (char*)malloc(sizeof(char) * 13);
     if (!tmp)
         return (0);
	tmp[12] = '\0';
     while (num != 0)
     {
         num_t = num % 16;
         if (num_t < 10)
             tmp[i--] = num_t + '0';
         else if (num_t < 16 && num_t >= 10)
             tmp[i--] = 'a' + num_t - 10;
         num = num / 16;
     }
    while (i >= 0)
		tmp[i--] = '0';
     return (tmp);
 }

/*
     if (ele.dot == 2)
     {
         if (ele.num[1] == -1)
         {
             ele.num[1] = ele.num[0];
             ele.num[0] = -1;
         }
         len = (len > ele.num[1]) ? ele.num[1] : len;
     }
*/
int	main()
{
	int*	data;
	char	*tmp;

	tmp = printf_x_cir(123, 'x');
	printf("%s:\n", tmp);
	tmp = printf_p_cir(12345);
	printf("%.5s\n", "hi");
	printf("%i\n", 0123);
}
