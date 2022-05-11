#include "main.h"

void listFiles(const char* dirname) {
    DIR* dir = opendir(dirname);
    if (dir == NULL) {
        return;
    }

    struct dirent* entity;
    entity = readdir(dir);
    while (entity != NULL) {
        if (_strcmp(entity->d_name, ".") != 0 && _strcmp(entity->d_name, "..") != 0)
            printf("%s ", entity->d_name);

        entity = readdir(dir);
    }
    printf("\n");
    closedir(dir);
}
