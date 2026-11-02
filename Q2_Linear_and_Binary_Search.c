#include <stdio.h>

int linearSearch(int a[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
        if (a[i] == key)
            return i;
    return -1;
}

int binarySearch(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main(void)
{
    int a[100], n, i, key, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
    {
        printf("Invalid size\\n");
        return 1;
    }

    printf("Enter elements in sorted order: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = linearSearch(a, n, key);
    if (result == -1)
        printf("Linear Search: Element not found\\n");
    else
        printf("Linear Search: Element found at position %d\\n", result + 1);

    result = binarySearch(a, n, key);
    if (result == -1)
        printf("Binary Search: Element not found\\n");
    else
        printf("Binary Search: Element found at position %d\\n", result + 1);

    return 0;
}
