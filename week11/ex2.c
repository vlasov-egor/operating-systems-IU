#include <stdio.h>
#include <dirent.h>

int main()
{
    DIR *r = opendir("/");
    struct dirent *d;
    while ((d = readdir(r)) != NULL)
    {
        printf("%s\n", d->d_name);
    }
    return 0;
}