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

/* Height is measured in number of nodes; empty tree height is 0. */
int findHeight(struct Node *root)
{
    int leftHeight, rightHeight;

    if (root == NULL) return 0;

    leftHeight = findHeight(root->left);
    rightHeight = findHeight(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

void displayLeafNodes(struct Node *root)
{
    if (root == NULL) return;

    if (root->left == NULL && root->right == NULL)
    {
        printf("%d ", root->data);
        return;
    }

    displayLeafNodes(root->left);
    displayLeafNodes(root->right);
}

int main(void)
{
    /* Example tree */
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);

    printf("Height of tree: %d\\n", findHeight(root));
    printf("Leaf nodes: ");
    displayLeafNodes(root);
    printf("\\n");
    return 0;
}
