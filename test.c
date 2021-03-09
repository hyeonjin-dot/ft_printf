#include <stdio.h>

int	main()
{
	int i = 0;
	printf("%*s:\n",0, "hello");
	while (i < 5)
	{
		printf("i\n");
		i++;
		if (i == 3)
		{
			printf("3\n");
			if (i == 3)
			{
				printf("here\n");
				continue;
			}
			printf("i == 3 \n");
		}
		printf("roop\n");
	}
}
