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

void reverseList(void)
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *nextNode;

    while (current != NULL)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    head = prev;
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
    int n, i, value;

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

    reverseList();

    printf("Reversed list: ");
    displayList();
    return 0;
}
