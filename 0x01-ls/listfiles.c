#include "main.h"

void listFiles(const char* dirname)
{
    DIR* dir = opendir(dirname);
    struct dirent* entity;

    if (dir == NULL) {
        return;
    }
    entity = readdir(dir);
    while (entity != NULL) {
        if (mystrcmp(entity->d_name, ".") != 0 && mystrcmp(entity->d_name, "..") != 0 && entity->d_name[0] != '.')
            printf("%s ", entity->d_name);

        entity = readdir(dir);
    }
    printf("\n");
    closedir(dir);
}
