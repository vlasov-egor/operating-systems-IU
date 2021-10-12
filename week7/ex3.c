#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    int new_n = 0;
    srand(time(NULL));

    printf("Enter size of ur array:\n");
    scanf("%d", &n);

    int *a = malloc(sizeof(int) * n);

    for (int i = 0; i < n; ++i)
    {
        a[i] = 33;
        printf("%d\n", a[i]);
    }

    printf("Enter new size of ur array:\n");

    scanf("%d", &new_n);

    a = realloc(a, sizeof(int) * new_n);

    for (int i = n; i < new_n; ++i)
    {
        a[i] = 0;
    }

    for (int i = 0; i < new_n; ++i)
    {
        printf("%d\n", a[i]);
    }
    printf("\n");

    return 0;
}