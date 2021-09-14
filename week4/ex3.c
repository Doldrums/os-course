#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[256];

    while (1)
    {

        char *input = malloc(sizeof(char) * 256);
        scanf("%s", input);

        if (strlen(input) == 0)
        {
            continue;
        }

        system(input);
    }
}