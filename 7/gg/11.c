#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

void parse_permissions(mode_t mode, char *perms)
{
	char rwx[] = {'r','w','x'};
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			perms[i*3+j] = (mode>>((2-i)*3+(2-j))&1)? rwx[j]: '-';//分成3组
	perms[9] = '\0';
}

int main()
{
	char perms[10];
	parse_permissions(0753, perms);
	printf("%s\n", perms);
	return 0;
}
