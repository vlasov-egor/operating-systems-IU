#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        // 10 * 1024 * 1024 = 10485760
        void *t = malloc(10485760);
        t = memset(t, 0, 10485760);
        sleep(1);
    }
    return 0;
}
