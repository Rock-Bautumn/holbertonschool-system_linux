#include "main.h"

void listFiles(const char* dirname) {
    DIR* dir = opendir(dirname);
    if (dir == NULL) {
        return;
    }

    /* printf("Reading files in: %s\n", dirname); */
    /*
        if (entity->d_type == DT_DIR && strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0) {
        char path[100] = { 0 };
        strcat(path, dirname);
        strcat(path, "/");
        strcat(path, entity->d_name);
        listFiles(path);
    }
    */

    struct dirent* entity;
    entity = readdir(dir);
    while (entity != NULL) {
        if (strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0)
            printf("%s ", entity->d_name);

        entity = readdir(dir);
    }
    printf("\n");
    closedir(dir);
}
