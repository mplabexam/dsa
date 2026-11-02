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

void deleteAtBeginning(void)
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty\\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd(void)
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty\\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
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
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);

    printf("Original list: ");
    displayList();

    deleteAtBeginning();
    printf("After deleting beginning: ");
    displayList();

    deleteAtEnd();
    printf("After deleting end: ");
    displayList();

    return 0;
}
