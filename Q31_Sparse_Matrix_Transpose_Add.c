#include <stdio.h>

#define MAX 100

struct Triplet
{
    int row, col, value;
};

void readSparse(struct Triplet a[], int *terms, int *rows, int *cols)
{
    int i, j, value;

    printf("Enter rows and columns: ");
    scanf("%d%d", rows, cols);

    a[0].row = *rows;
    a[0].col = *cols;
    *terms = 0;

    printf("Enter matrix elements row by row:\\n");
    for (i = 0; i < *rows; i++)
        for (j = 0; j < *cols; j++)
        {
            scanf("%d", &value);
            if (value != 0)
            {
                (*terms)++;
                a[*terms].row = i;
                a[*terms].col = j;
                a[*terms].value = value;
            }
        }

    a[0].value = *terms;
}

void displayTriplet(struct Triplet a[])
{
    int i;
    printf("Row Col Value\\n");
    for (i = 0; i <= a[0].value; i++)
        printf("%d   %d   %d\\n", a[i].row, a[i].col, a[i].value);
}

void transposeSparseMatrix(struct Triplet a[], struct Triplet t[])
{
    int i, j, k = 1;

    t[0].row = a[0].col;
    t[0].col = a[0].row;
    t[0].value = a[0].value;

    for (i = 0; i < a[0].col; i++)
        for (j = 1; j <= a[0].value; j++)
            if (a[j].col == i)
            {
                t[k].row = a[j].col;
                t[k].col = a[j].row;
                t[k].value = a[j].value;
                k++;
            }
}

int addSparseMatrices(struct Triplet a[], struct Triplet b[], struct Triplet c[])
{
    int i = 1, j = 1, k = 1;

    if (a[0].row != b[0].row || a[0].col != b[0].col)
        return 0;

    c[0].row = a[0].row;
    c[0].col = a[0].col;

    while (i <= a[0].value && j <= b[0].value)
    {
        int apos = a[i].row * a[0].col + a[i].col;
        int bpos = b[j].row * b[0].col + b[j].col;

        if (apos == bpos)
        {
            int sum = a[i].value + b[j].value;
            if (sum != 0)
            {
                c[k] = a[i];
                c[k].value = sum;
                k++;
            }
            i++;
            j++;
        }
        else if (apos < bpos)
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    while (i <= a[0].value) c[k++] = a[i++];
    while (j <= b[0].value) c[k++] = b[j++];

    c[0].value = k - 1;
    return 1;
}

int main(void)
{
    struct Triplet a[MAX], b[MAX], t[MAX], sum[MAX];
    int ta, tb, r1, c1, r2, c2;

    printf("First matrix:\\n");
    readSparse(a, &ta, &r1, &c1);
    printf("Second matrix:\\n");
    readSparse(b, &tb, &r2, &c2);

    printf("First matrix triplet form:\\n");
    displayTriplet(a);

    transposeSparseMatrix(a, t);
    printf("Transpose of first matrix:\\n");
    displayTriplet(t);

    if (addSparseMatrices(a, b, sum))
    {
        printf("Sum in triplet form:\\n");
        displayTriplet(sum);
    }
    else
        printf("Matrices must have the same dimensions to be added.\\n");

    return 0;
}
