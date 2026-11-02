#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop(void)
{
    struct Node *temp;
    if (top == NULL)
    {
        printf("Stack underflow\\n");
        return;
    }

    temp = top;
    printf("Popped: %d\\n", temp->data);
    top = top->next;
    free(temp);
}

void display(void)
{
    struct Node *temp = top;
    printf("Stack (top to bottom): ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\\n");
}

int main(void)
{
    int choice, value;
    do
    {
        printf("\\n1.Push  2.Pop  3.Display  0.Exit\\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter value: ");
            scanf("%d", &value);
            push(value);
        }
        else if (choice == 2) pop();
        else if (choice == 3) display();
    } while (choice != 0);

    return 0;
}
