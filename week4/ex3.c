#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[256];

    while (1)
    {
        // printf("$ ");

        fgets(input, sizeof input, stdin);

        if (strlen(input) == 0)
            continue;

        system(input);
    }
}