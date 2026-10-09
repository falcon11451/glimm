#include <stdio.h>

int x;

int lowbit(int x)
{
	return x&-x;
}

int main()
{
	scanf("%d", &x);
	printf("%d\n", lowbit(x));
	return 0;
}
