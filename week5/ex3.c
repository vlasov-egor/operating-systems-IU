#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int N = 8;
int count = 0;

int consumer_sleep_flag = 1;
int producer_sleep_flag = 1;

void *Сonsumer_func()
{
    while (1)
    {
        if (count == 0)
        {
            consumer_sleep_flag = 1;
            while (consumer_sleep_flag)
            {
            }
        }
        else
        {
            count--;
            if (count == 0)
            {
                consumer_sleep_flag = 0;
            }
            printf("%d", count);
        }
    }
}

void *Producer_func()
{
    while (1)
    {
        if (count == N)
        {
            producer_sleep_flag = 1;
            while (producer_sleep_flag)
            {
            }
        }
        else
        {
            count++;
            if (count == 1)
            {
                producer_sleep_flag = 0;
            }
            printf("%d", count);
        }
    }
}

int main()
{
    pthread_t consumer_thrd;
    pthread_t producer_thrd;

    pthread_create(&consumer_thrd, NULL, Сonsumer_func, NULL);
    pthread_create(&producer_thrd, NULL, Producer_func, NULL);

    pthread_join(&consumer_thrd, 0);
    pthread_join(&producer_thrd, 0);
}