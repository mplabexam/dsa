#include <stdio.h>

void removeDuplicates(int a[], int *n)
{
    int i, j, k;

    for (i = 0; i < *n; i++)
    {
        for (j = i + 1; j < *n; j++)
        {
            if (a[i] == a[j])
            {
                for (k = j; k < *n - 1; k++)
                    a[k] = a[k + 1];

                (*n)--;
                j--;
            }
        }
    }
}

void displayArray(int a[], int n)
{
    int i;
    printf("Array after removing duplicates: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\\n");
}

int main(void)
{
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
    {
        printf("Invalid size\\n");
        return 1;
    }

    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    removeDuplicates(a, &n);
    displayArray(a, n);

    return 0;
}
