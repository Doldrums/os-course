#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define N 8

int count = 0;

int lock1 = 1;
int lock2 = 1;

void *tfunc1()
{
    while (1)
    {
        if (count == 0)
        {
            lock1 = 1;

            while (lock1) {}
        }
        else
        {
            count--;

            if (count == 0)
            {
                lock1 = 0;
            }
            
            printf("%d", count);
        }
    }
}

void *tfunc2()
{
    while (1)
    {
        if (count == N)
        {
            lock2 = 1;

            while (lock2) {}
        }
        else
        {
            count++;
            
            if (count == 1)
            {
                lock2 = 0;
            }
            
            printf("%d", count);
        }
    }
}

int main()
{
    pthread_t t2;
    pthread_t t1;
    
    pthread_create(&t1, NULL, tfunc1, NULL);
    pthread_create(&t2, NULL, tfunc2, NULL);
    pthread_join(&t1, 0);
    pthread_join(&t2, 0);
    
    return 0;
}