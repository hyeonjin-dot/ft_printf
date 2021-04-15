#include <stdio.h>
#include <string.h>

int	main()
{
	int*	data;
	char	tmp;

	tmp = 'a';
	data = &tmp;
	printf("%.14p:\n", data);
	printf("%-03x\n", 10);
}
