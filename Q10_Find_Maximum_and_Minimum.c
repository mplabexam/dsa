#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtEnd(int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    struct Node *temp;

    if (newNode == NULL)
        return;

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void findMaximum(void)
{
    struct Node *temp;
    int max;

    if (head == NULL)
    {
        printf("List is empty\\n");
        return;
    }

    max = head->data;
    temp = head->next;

    while (temp != NULL)
    {
        if (temp->data > max)
            max = temp->data;
        temp = temp->next;
    }

    printf("Maximum element: %d\\n", max);
}

void findMinimum(void)
{
    struct Node *temp;
    int min;

    if (head == NULL)
    {
        printf("List is empty\\n");
        return;
    }

    min = head->data;
    temp = head->next;

    while (temp != NULL)
    {
        if (temp->data < min)
            min = temp->data;
        temp = temp->next;
    }

    printf("Minimum element: %d\\n", min);
}

void displayList(void)
{
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\\n");
}

int main(void)
{
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
    {
        printf("Enter between 1 and 100 nodes\\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &value);
        insertAtEnd(value);
    }

    displayList();
    findMaximum();
    findMinimum();

    return 0;
}
