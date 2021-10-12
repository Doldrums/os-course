#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int n = 10;

int main()
{
    
    for (int i = 0; i < n; ++i)
    {
        void *t = malloc(1024 * 1024 * 10);
        t = memset(t, 0, 1024 * 1024 * 10);
        
        sleep(1);
    }
    return 0;
}
