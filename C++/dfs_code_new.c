
#include <stdio.h>
#include <stdlib.h>

int n;        // number of nodes in graph
int *visited; // array to keep a track of nodes visited

void dfs(int i, int g[n][n]);

int main()
{
    int i, j, node;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int g[n][n];
    visited = (int *)calloc(n, sizeof(int));

    printf("Enter the adjacency matrix of the graph:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &g[i][j]);
    }

    printf("Enter the source node: ");
    scanf("%d", &node);
    printf("\nThe nodes reachable from %d are:\n", node);
    dfs(node - 1, g);

    return 0;
}

void dfs(int i, int g[n][n])
{
    int j;

    visited[i] = 1;
    printf("%d ", i + 1);

    for (j = 0; j < n; j++)
    {
        if (!visited[j] && g[i][j] == 1)
            dfs(j, g);
    }
}
