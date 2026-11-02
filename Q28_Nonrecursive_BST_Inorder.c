#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int value)
{
    struct Node *node = malloc(sizeof(struct Node));
    if (node == NULL) exit(1);
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

struct Node *insertNode(struct Node *root, int value)
{
    if (root == NULL) return createNode(value);
    if (value < root->data) root->left = insertNode(root->left, value);
    else if (value > root->data) root->right = insertNode(root->right, value);
    return root;
}

void push(struct Node *stack[], int *top, struct Node *node)
{
    if (*top < MAX - 1) stack[++(*top)] = node;
}

void inorderNonRecursive(struct Node *root)
{
    struct Node *stack[MAX], *current = root;
    int top = -1;

    while (current != NULL || top != -1)
    {
        while (current != NULL)
        {
            push(stack, &top, current);
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

int main(void)
{
    struct Node *root = NULL;
    int n, i, value;

    printf("Enter number of values: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("Non-recursive inorder: ");
    inorderNonRecursive(root);
    printf("\\n");
    return 0;
}
