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

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);

    return root;
}

struct Node *searchNode(struct Node *root, int key)
{
    if (root == NULL || root->data == key) return root;

    if (key < root->data)
        return searchNode(root->left, key);
    return searchNode(root->right, key);
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(void)
{
    struct Node *root = NULL, *found;
    int n, i, value, key;

    printf("Enter number of values: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("BST inorder: ");
    inorder(root);
    printf("\\nEnter key to search: ");
    scanf("%d", &key);

    found = searchNode(root, key);
    if (found != NULL) printf("Element found\\n");
    else printf("Element not found\\n");

    return 0;
}
