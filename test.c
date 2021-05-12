#include <stdio.h>
#include <string.h>
#include <unistd.h>
int	main()
{
	int i = -2147483648;
	write(1, "123", 6);
	write(1, "\n", 1);
	printf("%d\n", printf("[%7.4d]", -123));

	i = 4;
	while (i-- > 0)
		printf("i\n");
}
