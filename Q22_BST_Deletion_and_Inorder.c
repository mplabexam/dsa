#include <stdio.h>
#include <stdlib.h>

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

struct Node *minimumNode(struct Node *root)
{
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}

struct Node *deleteNode(struct Node *root, int key)
{
    struct Node *temp;

    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        temp = minimumNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void Recursive_inorder(struct Node *root)
{
    if (root != NULL)
    {
        Recursive_inorder(root->left);
        printf("%d ", root->data);
        Recursive_inorder(root->right);
    }
}

int main(void)
{
    struct Node *root = NULL;
    int n, i, value, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("Inorder before deletion: ");
    Recursive_inorder(root);

    printf("\\nEnter value to delete: ");
    scanf("%d", &key);
    root = deleteNode(root, key);

    printf("Inorder after deletion: ");
    Recursive_inorder(root);
    printf("\\n");

    return 0;
}
