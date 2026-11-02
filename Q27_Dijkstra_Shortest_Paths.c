#include <stdio.h>

#define MAX 100
#define INF 1000000000

int main(void)
{
    int graph[MAX][MAX], dist[MAX], visited[MAX];
    int n, source, i, j, min, u, v, w;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX) return 1;

    printf("Enter weighted adjacency matrix (0 means no edge; diagonal 0):\\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
            if (i != j && graph[i][j] == 0)
                graph[i][j] = INF;
        }

    printf("Enter source vertex (0-based): ");
    scanf("%d", &source);
    if (source < 0 || source >= n) return 1;

    for (i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[source] = 0;

    for (i = 0; i < n; i++)
    {
        min = INF;
        u = -1;

        for (j = 0; j < n; j++)
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }

        if (u == -1) break;
        visited[u] = 1;

        for (v = 0; v < n; v++)
        {
            if (!visited[v] && graph[u][v] != INF)
            {
                w = graph[u][v];
                if (dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
            }
        }
    }

    printf("Shortest distances from %d:\\n", source);
    for (i = 0; i < n; i++)
    {
        if (dist[i] == INF) printf("To %d: unreachable\\n", i);
        else printf("To %d: %d\\n", i, dist[i]);
    }

    return 0;
}
