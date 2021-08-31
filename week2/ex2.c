//
// Created by Orina on 31.08.2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *string = malloc(256 * sizeof(char)), s = "";
    fgets(string, 256, stdin);
    int temp = strlen(string);
    for (int i = 0; i < temp / 2; i++)
    {
        s = string[i];
        string[i] = string[temp - 1 - i];
        string[temp - 1 - i] = s;
    }
    printf("%s", string);
}