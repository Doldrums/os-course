//
// Created by Orina on 31.08.2021.
//
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int a, b;
    char *str = malloc(256*sizeof(char));
    printf("first one:\n");
    fgets(str, 256, stdin);
    a = atoi(str);
    printf("second one:\n");
    fgets(str, 256, stdin);
    b = atoi(str);
    swap(&a, &b);
    printf("now, first one is: %d\n", a);
    printf("and second one is: %d\n", b);
}
