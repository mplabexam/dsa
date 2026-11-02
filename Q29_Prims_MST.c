#include <stdio.h>

#define MAX 100
#define INF 1000000000

void primMST(int graph[MAX][MAX], int n)
{
    int parent[MAX], key[MAX], selected[MAX];
    int i, j, u, min, total = 0;

    for (i = 0; i < n; i++)
    {
        key[i] = INF;
        selected[i] = 0;
        parent[i] = -1;
    }
    key[0] = 0;

    for (i = 0; i < n; i++)
    {
        min = INF;
        u = -1;

        for (j = 0; j < n; j++)
            if (!selected[j] && key[j] < min)
            {
                min = key[j];
                u = j;
            }

        if (u == -1)
        {
            printf("Graph is not connected\\n");
            return;
        }

        selected[u] = 1;

        for (j = 0; j < n; j++)
            if (graph[u][j] > 0 && !selected[j] && graph[u][j] < key[j])
            {
                key[j] = graph[u][j];
                parent[j] = u;
            }
    }

    printf("MST edges:\\n");
    for (i = 1; i < n; i++)
    {
        printf("%d - %d : %d\\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }
    printf("Total minimum cost: %d\\n", total);
}

int main(void)
{
    int graph[MAX][MAX], n, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX) return 1;

    printf("Enter weighted adjacency matrix (0 means no edge):\\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    primMST(graph, n);
    return 0;
}
