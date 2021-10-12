#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>


int main()
{
    int *ptr = NULL;
    const int memory = 1024*1024;

    for (int i = 0; i < 10; ++i)
    {
        ptr = malloc(10 * memory);
        memset(ptr, 0, 10 * memory);

        struct rusage usage;
        getrusage(RUSAGE_SELF, &usage);
        printf("Memory required: %ld", usage.ru_maxrss);

        sleep(1);
    }

    free(ptr);
    return 0;
}