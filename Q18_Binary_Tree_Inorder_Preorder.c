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

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(void)
{
    /* Example tree:
             1
            / \\
           2   3
    */
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    printf("Inorder: ");
    inorder(root);
    printf("\\nPreorder: ");
    preorder(root);
    printf("\\n");

    return 0;
}
