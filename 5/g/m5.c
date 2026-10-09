#include <stdio.h>

// 请补全以下代码
int hasCommonChar(const char *s1, const char *s2) {
     	int mask1 = 0;
     	int mask2 = 0;
	for (int i = 0; s1[i]; i++) mask1 |= 1<<(s1[i]-'a');
	for (int i = 0; s2[i]; i++) mask2 |= 1<<(s2[i]-'a');
	return !!(mask1&mask2);
}

char a[100001], b[100001];

int main()
{
	scanf("%s%s", a, b);
	printf("%d\n", hasCommonChar(a, b));
	return 0;
}
