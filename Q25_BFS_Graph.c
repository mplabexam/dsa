#include <stdio.h>

#define MAX 100

int graph[MAX][MAX], visited[MAX], queue[MAX];
int n;

void BFS(int start)
{
    int front = 0, rear = 0, i, v;

    for (i = 0; i < n; i++) visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS traversal: ");

    while (front < rear)
    {
        v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++)
        {
            if (graph[v][i] && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\\n");
}

int main(void)
{
    int edges, i, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX) return 1;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (i = 0; i < edges; i++)
    {
        printf("Enter edge u v (0-based): ");
        scanf("%d%d", &u, &v);
        if (u >= 0 && u < n && v >= 0 && v < n)
            graph[u][v] = graph[v][u] = 1;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);
    if (start < 0 || start >= n) return 1;

    BFS(start);
    return 0;
}
