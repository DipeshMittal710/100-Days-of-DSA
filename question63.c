#include <stdio.h>

int adj[100][100];
int visited[100];
int n;

void dfs(int vertex) {

    visited[vertex] = 1;

    printf("%d ", vertex);

    for (int i = 0; i < n; i++) {

        if (adj[vertex][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {

    int edges;

    scanf("%d %d", &n, &edges);

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }

        visited[i] = 0;
    }

    for (int i = 0; i < edges; i++) {

        int u, v;

        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        adj[v][u] = 1; 
    }

    int start;

    scanf("%d", &start);

    dfs(start);

    return 0;
}