//
// Created by Orina on 31.08.2021.
//
#include <stdio.h>
#include <stdlib.h>

void f(int n)
{
    int length = n * 2 - 1;
    char *result = malloc(length * sizeof(char));
    int a = length / 2, b = length / 2;
    for (int i = 0; i < length; i++)
    {
        result[i] = ' ';
    }
    for (int i = 0; i < n; i++)
    {
        result[a] = '*';
        result[b] = '*';
        a--;
        b++;
        printf("%s\n", result);
    }
}

int main()
{
    int n;
    char *pVoid = malloc(256 * sizeof(char));
    fgets(pVoid, 256, stdin);
    n = atoi(pVoid);
    f(n);
}
