#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    DIR *root = opendir("/");

    struct dirent *d;
    d = readdir(root);

    while (d != NULL)
        printf("%s\n", d->d_name);
}