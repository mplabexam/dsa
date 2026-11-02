#include <stdio.h>
#define MAX 100

int stack[MAX], top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\\n");
        return;
    }
    stack[++top] = value;
}

void pop(void)
{
    if (top == -1)
    {
        printf("Stack underflow\\n");
        return;
    }
    printf("Popped: %d\\n", stack[top--]);
}

void display(void)
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty\\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for (i = top; i >= 0; i--) printf("%d ", stack[i]);
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
