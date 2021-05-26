#include <stdio.h>

int	main()
{
	int	a;
	int	*b;

	a = 3;
	b = &a;
	printf("%d\n\n", printf("(%*.*s)", -4,1,"hello"));
	printf("%d\n\n", printf("%p", b));
}
