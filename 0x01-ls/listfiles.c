#include "main.h"

void listFiles(parsedCmdLine *lsArgs, char* dirname)
{
	DIR* dir = opendir(dirname);
	DIR* dir2 = opendir("./noreaddir");
	struct dirent* entity;
	char *thisname;

	(void) dir2;
	(void) lsArgs;
	if (dir == NULL)
	{
		return;
	}
	entity = readdir(dir);
	while (entity != NULL)
	{
		thisname = entity->d_name;
		if (mystrcmp(thisname, ".") != 0 && mystrcmp(thisname, "..") != 0 && thisname[0] != '.')
			printf("%s ", entity->d_name);

		entity = readdir(dir);
	}
	printf("\n");
	closedir(dir);
	/*
	if (dir2 == NULL)
	{
		perror("unable to open testdir");
		lsErr(lsArgs, "cannot open directory", dirname);
		return;

	}
	entity = readdir(dir2);
	while (entity != NULL)
	{
		thisname = entity->d_name;
		if (mystrcmp(thisname, ".") != 0 && mystrcmp(thisname, "..") != 0 && thisname[0] != '.')
			{
				printf("%s ", entity->d_name);
			}

		entity = readdir(dir2);
	}
	printf("\n");
	closedir(dir2);
	*/
}

