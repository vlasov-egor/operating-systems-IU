#include <stdio.h>
#include <unistd.h>

int main()
{
    int n = 0;
    pid_t is_parent = fork();

    is_parent ? printf("Hello from parent [%d - %d]\n", getpid(), n++) : printf("Hello from child [%d - %d]\n", getpid(), n++);
}