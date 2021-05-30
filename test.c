#include <stdio.h>

int	main ()
{
	printf("%-*.*s\n",-4, 3, "hello");
	printf("%-*.*s\n", -4, -3, "hello");
}
