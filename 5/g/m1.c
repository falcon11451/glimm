#include <stdio.h>

int x, idx;

int main()
{
	scanf("%d%d", &x, &idx);
	printf("%d\n", (x>>(idx-1)) &1);
	return 0;
}
