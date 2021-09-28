#include <stdio.h>
#include <stdlib.h>

void find_min(int *a, int *b, int n, int time, int *min_time, int *mini)
{
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > time)
        {
            continue;
        }
        else if (b[i] < min_time)
        {
            min_time = b[i];
            mini = i;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int *a = (int *)malloc(sizeof(int) * n);
    int *b = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d", a + i, b + i);
    }

    int completed = 0;
    int time = 0;

    int average_time = 0;
    int average_waiting = 0;
    while (completed != n)
    {
        int min_time = 9999999;
        int mini = -1;

        find_min(a, b, n, time, &min_time, &mini);

        if (mini == -1)
        {
            printf("No processes to execute\n", time);
            time++;
            continue;
        }

        int wt = time - a[mini];

        printf("Executing %d\n", time, mini);
        time += b[mini];
        printf("%d has been executed\n", time, mini);
        b[mini] = a[mini] = -1;
        completed++;

        int turn_around = time - a[mini];
        printf("Process %d: turn around time (TAT): %d", mini, turn_around);
        printf("Waiting time (WT): %d", wt);
        average_time += turn_around;
        average_waiting += wt;
    }

    printf("Completion time: %d\n", time);
    printf("Average Turnaround time: %f\n", average_time * 1.0 / n);
    printf("Average waiting time: %f\n", average_waiting * 1.0 / n);
    return 0;
}
