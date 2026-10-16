#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAXLEN 4096

ino_t get_inode(const char *path) {
	struct stat statbuf;
	if (stat(path, &statbuf) == -1) 
	{
	        perror("stat failed");
	       exit(EXIT_FAILURE);
	}
	return statbuf.st_ino;
}

char *getName(ino_t son)
{
	DIR *dir = opendir(".");
	struct dirent *entry = readdir(dir);
	for (; entry && entry->d_ino != son; entry = readdir(dir)) ;
	char *ret = (char *)malloc(sizeof(char)*MAXLEN);
	memcpy(ret, entry->d_name, strlen(entry->d_name)+1);
	closedir(dir);
	return ret;
}

void dfs(ino_t son)
{
	if (get_inode(".") == get_inode("..")) 
	{
		char *sonName = getName(son);
		printf("/%s", sonName);
		free(sonName);
		return;
	}
	char *sonName = getName(son);
	ino_t thiss = get_inode(".");
	chdir("..");
	dfs(thiss);
	printf("/%s", sonName);
	free(sonName);
}

void myPwd()
{
	ino_t thiss = get_inode(".");
	if (get_inode(".") == get_inode("..")) //AI补充了这个特判 
	{
		printf("/");
		return;
	}
	chdir("..");
	dfs(thiss);
}

int main()
{
	myPwd();
	printf("\n");
	return 0;
}
