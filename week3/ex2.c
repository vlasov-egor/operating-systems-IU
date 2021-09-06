#include <stdio.h>
int n, arr[50], swapped;

void bubble_sort()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swapped = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swapped;
            }
        }
    }
}

int main()
{
    printf("Enter how many elements are there:\n");
    scanf("%d", &n);

    printf("Enter your array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    bubble_sort();

    printf("Sorted:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}