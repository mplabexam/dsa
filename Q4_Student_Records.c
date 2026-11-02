#include <stdio.h>

struct Student
{
    int roll;
    char name[50];
    float marks;
};

void sortRecords(struct Student s[], int n)
{
    int i, j, min;
    struct Student temp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (s[j].marks < s[min].marks)
                min = j;

        temp = s[i];
        s[i] = s[min];
        s[min] = temp;
    }
}

void displayRecords(struct Student s[], int n)
{
    int i;
    printf("\\nRoll\\tName\\tMarks\\n");
    for (i = 0; i < n; i++)
        printf("%d\\t%s\\t%.2f\\n", s[i].roll, s[i].name, s[i].marks);
}

int main(void)
{
    struct Student s[100];
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
    {
        printf("Invalid number of students\\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter roll number, name and marks: ");
        scanf("%d %49s %f", &s[i].roll, s[i].name, &s[i].marks);
    }

    sortRecords(s, n);
    displayRecords(s, n);
    return 0;
}
