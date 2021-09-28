#include <stdio.h>
#include <stdlib.h>

void find_min(int *a, int last_index, int n, int time, int *mini)
{
    for (int i = 0; i < n; ++i)
    {
        int current = (last_index + i) % n;
        if (a[i] > time || a[i] == -1)
            continue;
        mini = i;
        break;
    }
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    int *a = (int *)malloc(sizeof(int) * n);
    int *b = (int *)malloc(sizeof(int) * n);
    int *wt = (int *)calloc(sizeof(int) * n, 0);
    int *last_stop = (int *)calloc(sizeof(int) * n, -1);
    int *start_time = (int *)calloc(sizeof(int) * n, -1);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d", a + i, b + i);
    }

    int completed = 0;
    int time = 0;

    int last_index = 0;
    while (completed != n)
    {
        int mini = -1;
        find_min(a, last_index, n, time, &mini);

        if (mini == -1)
        {
            printf("Waiting for executing\n", time);
            time++;
            continue;
        }

        last_index = mini;

        printf("Starting executing %d", time, mini);
        if (last_stop[mini] != -1)
        {
            wt += time - last_stop[mini];
        }
        if (start_time[mini] == -1)
            start_time[mini] = time;
        if (b[mini] > q)
        {
            b[mini] -= q;
            time += q;
            printf("Stopped %d due to exceeding the quantum", time, mini);
        }
        else
        {
            time += b[mini];
            a[mini] = b[mini] = -1;
            printf("Process %d has been executed", time, mini);
            completed++;
        }
        last_stop[mini] = time;
    }
    int wait_sum = 0;
    int turn_sum = 0;
    for (int i = 0; i < n; i++)
    {
        int turn_time = last_stop[i] - start_time[i];
        int wait_time = wt[i];
        printf("Process %d: turn around time (TAT): %d", i, wait_time);
        printf("Waiting time (WT): %d", turn_time);
        wait_sum += wait_time;
        turn_sum += turn_time;
    }
    printf("Completion time: %d\n", time);
    printf("Average Turnaround time: %f\n", turn_sum * 1.0 / n);
    printf("Average waiting time: %f\n", wait_sum * 1.0 / n);
    return 0;
}
