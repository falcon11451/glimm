#include <stdio.h>

int main()
{
	int sum = 0, sum1 = 0, i = 1;
	while (i <= 10)
	{
		sum += i;
		i++;
	}
	i = 1;
	do {
		sum1 += i;
		i++;
	} while (i <= 10);
	printf("%d %d\n", sum, sum1);
	return 0;
}
