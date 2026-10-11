#include <stdio.h>

typedef struct{
	char name[64];
	int age;
} Person;

Person p[100];
int cnt;

int main()
{
	char opt = 'y';
	while (opt != 'n' && cnt < 100)
	{
		cnt++;
		printf("input name(length <= 63, no space) and age\n(name age):");
		scanf("%s%d", p[cnt].name, &(p[cnt].age));
		printf("name:%s\nage:%d\nperson:%d\n", p[cnt].name, p[cnt].age, cnt);
		printf("continue?(press 'y' or 'n'):");
		scanf(" %c", &opt);
	}
	printf("person:%d\n", cnt);
	return 0;
}
