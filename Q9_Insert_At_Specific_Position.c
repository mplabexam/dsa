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

void insertAtPosition(int value, int position)
{
    struct Node *newNode, *temp;
    int i;

    if (position < 1)
    {
        printf("Invalid position\\n");
        return;
    }

    newNode = malloc(sizeof(struct Node));
    if (newNode == NULL)
        return;

    newNode->data = value;

    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    temp = head;
    for (i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Invalid position\\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void displayList(void)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\\n");
}

int main(void)
{
    int n, i, value, position;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n < 0 || n > 100)
    {
        printf("Invalid number of nodes\\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &value);
        insertAtEnd(value);
    }

    printf("Original list: ");
    displayList();

    printf("Enter value to insert: ");
    scanf("%d", &value);

    printf("Enter position (starting from 1): ");
    scanf("%d", &position);

    insertAtPosition(value, position);

    printf("Updated list: ");
    displayList();
    return 0;
}
