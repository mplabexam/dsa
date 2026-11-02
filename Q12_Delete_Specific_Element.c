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
    if (newNode == NULL) return;

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

void deleteSpecificElement(int key)
{
    struct Node *temp = head, *prev = NULL;

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Element not found\\n");
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
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
    int n, i, value, key;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    if (n < 0 || n > 100) return 1;

    for (i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &value);
        insertAtEnd(value);
    }

    printf("Original list: ");
    displayList();

    printf("Enter value to delete: ");
    scanf("%d", &key);
    deleteSpecificElement(key);

    printf("Updated list: ");
    displayList();
    return 0;
}
