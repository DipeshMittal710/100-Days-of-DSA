#include <stdio.h>

int adj[100][100];
int visited[100];
int recStack[100];
int n;

int dfs(int vertex) {

    visited[vertex] = 1;
    recStack[vertex] = 1;

    for (int i = 0; i < n; i++) {

        if (adj[vertex][i]) {

            if (!visited[i]) {

                if (dfs(i))
                    return 1;
            }
            else if (recStack[i]) {
                return 1;
            }
        }
    }

    recStack[vertex] = 0;

    return 0;
}

int main() {

    int edges;

    scanf("%d %d", &n, &edges);

    for (int i = 0; i < n; i++) {

        visited[i] = 0;
        recStack[i] = 0;

        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < edges; i++) {

        int u, v;

        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
    }

    int hasCycle = 0;

    for (int i = 0; i < n; i++) {

        if (!visited[i]) {

            if (dfs(i)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}