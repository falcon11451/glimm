#include <stdio.h>

int x, n, t;

int main()
{
	scanf("%d%d%d", &x, &n, &t);
	if (t) printf("%d\n", x|(1<<(n-1)));
	else printf("%d\n", x&~(1<<(n-1)));
	return 0;
}
