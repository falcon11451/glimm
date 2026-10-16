#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

void parse_permissions(mode_t mode, char *perms)
{
	char rwx[] = {'r','w','x'};

	mode_t m = 0000;
	for (int i = 8; i >= 0; i--)
		m |= ((mode>>i)&1)<<(8-i);//reverse mode

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			perms[i*3+j] = (m>>(i*3+j))&1? rwx[j]: '-';

	perms[9] = '\0';
}

int main()
{
	char perms[10];
	parse_permissions(0753, perms);
	printf("%s\n", perms);
	return 0;
}
