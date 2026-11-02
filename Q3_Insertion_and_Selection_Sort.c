#include <stdio.h>

void insertionSort(int a[], int n)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void selectionSort(int a[], int n)
{
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void displayArray(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\\n");
}

int main(void)
{
    int a[100], b[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
    {
        printf("Invalid size\\n");
        return 1;
    }

    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    insertionSort(a, n);
    selectionSort(b, n);

    printf("Insertion Sort: ");
    displayArray(a, n);

    printf("Selection Sort: ");
    displayArray(b, n);

    printf("Insertion Sort: Best O(n), Average/Worst O(n^2)\\n");
    printf("Selection Sort: Best/Average/Worst O(n^2)\\n");

    return 0;
}
