//
// Created by Orina on 02.11.2021.
//
#include <stdio.h>
#include <dirent.h>


int main() {
    DIR* root = opendir("/");
    struct dirent* current;
    while ((current = readdir(root)) != NULL) printf("%s\n", current->d_name);
    closedir(root);
    return 0;
}


