#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *tfunc(int n)
{
    printf("thread #%d\n", n);
}

int main()
{
    const int count = 10;
    pthread_t *ts = malloc(sizeof(pthread_t) * count);

    for (int i = 0; i < count; i++)
    {
        printf("init thread #%d\n", i);
        pthread_create(&ts[i], NULL, tfunc, i);
    }

    for (int j = 0; j < count; j++)
    {
        pthread_join(ts[j], 0);
        printf("join thread #%d\n", j);
    }

    return 0;
}