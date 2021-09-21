#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *create(int id)
{
    printf("thread number: %d!\n", id);
}

int main()
{
    const int N = 10;
    pthread_t *container = malloc(sizeof(pthread_t) * N);

    for (int i = 0; i < N; ++i)
    {
        printf("init thread number: %d\n", i);
        pthread_create(&container[i], NULL, create, i);
    }

    for (int i = 0; i < N; ++i)
    {
        pthread_join(container[i], 0);
        printf("stop thread number: %d\n", i);
    }
}

//  gcc -pthread async_ex1.c
