#include <stdio.h>

#define MAXV 100
#define MAXE 1000

struct Edge
{
    int u, v, weight;
};

struct Edge edges[MAXE];
int parent[MAXV], rankSet[MAXV];

int findParent(int x)
{
    if (parent[x] != x)
        parent[x] = findParent(parent[x]);
    return parent[x];
}

void unionSets(int a, int b)
{
    a = findParent(a);
    b = findParent(b);

    if (a == b) return;

    if (rankSet[a] < rankSet[b])
        parent[a] = b;
    else if (rankSet[a] > rankSet[b])
        parent[b] = a;
    else
    {
        parent[b] = a;
        rankSet[a]++;
    }
}

void kruskalMST(int n, int m)
{
    int i, j, count = 0, total = 0;
    struct Edge temp;

    for (i = 0; i < m; i++)
        for (j = 0; j < m - i - 1; j++)
            if (edges[j].weight > edges[j + 1].weight)
            {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }

    for (i = 0; i < n; i++)
    {
        parent[i] = i;
        rankSet[i] = 0;
    }

    printf("MST edges:\\n");
    for (i = 0; i < m && count < n - 1; i++)
    {
        if (findParent(edges[i].u) != findParent(edges[i].v))
        {
            unionSets(edges[i].u, edges[i].v);
            printf("%d - %d : %d\\n", edges[i].u, edges[i].v, edges[i].weight);
            total += edges[i].weight;
            count++;
        }
    }

    if (count != n - 1)
        printf("Graph is not connected; MST not possible\\n");
    else
        printf("Total minimum cost: %d\\n", total);
}

int main(void)
{
    int n, m, i;

    printf("Enter number of vertices and edges: ");
    scanf("%d%d", &n, &m);
    if (n < 1 || n > MAXV || m < 0 || m > MAXE) return 1;

    for (i = 0; i < m; i++)
    {
        printf("Enter edge u v weight (vertices 0 to %d): ", n - 1);
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].weight);
        if (edges[i].u < 0 || edges[i].u >= n ||
            edges[i].v < 0 || edges[i].v >= n)
        {
            printf("Invalid vertex\\n");
            return 1;
        }
    }

    kruskalMST(n, m);
    return 0;
}
