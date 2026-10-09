#include <stdio.h>
#include <stdbool.h>

bool a[101], b[101];
int sza, szb, l, r;

int main()
{
	char ch;
	while ((ch = getchar()) != ' ')
		a[++sza] = ch-'0';
	while ((ch = getchar()) != ' ')
		b[++szb] = ch-'0';
	scanf("%d%d", &l, &r);
	for (int i = l; i <= r; i++)
		printf("%d", a[i]&b[i]);
	printf("\n");
	return 0;
}
