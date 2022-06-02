#include "main.h"

void listFiles(const char* dirname)
{
	DIR* dir = opendir(dirname);
	struct dirent* entity;
	char *thisname;

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
	dir = opendir(dirname);
	entity = readdir(dir);
	while (entity != NULL)
	{
		thisname = entity->d_name;
		if (mystrcmp(thisname, ".") != 0 && mystrcmp(thisname, "..") != 0 && thisname[0] != '.')
			{
				printf("%s ", entity->d_name);
				
			}

		entity = readdir(dir);
	}
	printf("\n");
	closedir(dir);
}

