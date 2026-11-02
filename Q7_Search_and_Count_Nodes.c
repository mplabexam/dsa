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

void searchElement(int key)
{
    struct Node *temp = head;
    int position = 1;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Element found at position %d\\n", position);
            return;
        }
        temp = temp->next;
        position++;
    }

    printf("Element not found\\n");
}

void countNodes(void)
{
    struct Node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("Total number of nodes: %d\\n", count);
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

    displayList();

    printf("Enter element to search: ");
    scanf("%d", &key);

    searchElement(key);
    countNodes();
    return 0;
}
