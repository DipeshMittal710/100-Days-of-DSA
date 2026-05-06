#include <stdio.h>

int adj[100][100];
int visited[100];
int n;

void dfs(int vertex) {

    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {

        if (adj[vertex][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {

    int m;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {

        visited[i] = 0;

        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {

        int u, v;

        scanf("%d %d", &u, &v);

        adj[u - 1][v - 1] = 1;
        adj[v - 1][u - 1] = 1;
    }

    dfs(0);

    int connected = 1;

    for (int i = 0; i < n; i++) {

        if (!visited[i]) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("CONNECTED\n");
    else
        printf("NOT CONNECTED\n");

    return 0;
}