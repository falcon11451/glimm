#include <stdio.h>

typedef struct{
	char name[11];
	char sex;
	int age;
	double height;
} PerInfo;

typedef struct{
	char name[11];
	int age;
	double height;
	char sex;
} PerInfo1;

int main()
{
	printf("%lu %lu\n", sizeof(PerInfo), sizeof(PerInfo1));
	return 0;
}
