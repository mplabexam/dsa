#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct Node
{
    int vertex;
    struct Node *next;
};

struct Node *adj[MAX];
int vertices;

void insertEdge(int u, int v)
{
    struct Node *node = malloc(sizeof(struct Node));
    if (node == NULL) return;
    node->vertex = v;
    node->next = adj[u];
    adj[u] = node;

    node = malloc(sizeof(struct Node));
    if (node == NULL) return;
    node->vertex = u;
    node->next = adj[v];
    adj[v] = node;
}

void displayGraph(void)
{
    int i;
    struct Node *temp;

    for (i = 0; i < vertices; i++)
    {
        printf("%d: ", i);
        temp = adj[i];
        while (temp != NULL)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\\n");
    }
}

int main(void)
{
    int edges, i, u, v;

    printf("Enter number of vertices (max %d): ", MAX);
    scanf("%d", &vertices);
    if (vertices < 1 || vertices > MAX) return 1;

    for (i = 0; i < vertices; i++) adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (i = 0; i < edges; i++)
    {
        printf("Enter edge (u v), vertices numbered 0 to %d: ", vertices - 1);
        scanf("%d%d", &u, &v);
        if (u >= 0 && u < vertices && v >= 0 && v < vertices)
            insertEdge(u, v);
    }

    displayGraph();
    return 0;
}
