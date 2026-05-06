#include <stdio.h>

int adj[100][100];
int visited[100];
int stack[100];
int top = -1;
int n;

void dfs(int vertex) {

    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {

        if (adj[vertex][i] && !visited[i]) {
            dfs(i);
        }
    }

    stack[++top] = vertex;
}

int main() {

    int edges;

    scanf("%d %d", &n, &edges);

    for (int i = 0; i < n; i++) {

        visited[i] = 0;

        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < edges; i++) {

        int u, v;

        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
    }

    for (int i = 0; i < n; i++) {

        if (!visited[i]) {
            dfs(i);
        }
    }

    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}